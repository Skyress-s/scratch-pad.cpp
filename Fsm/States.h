#pragma once

// #include "Turnstile.h"

#include <array>
#include <cstdint>
#include <optional>
#include <string>

#include "../CoroDefs.h"

struct UpdateEvent
{
    explicit UpdateEvent(Coro::push_type& Coro)
        : m_Coro(Coro)
    { }

    Coro::push_type& m_Coro;
};



namespace states {
    // using namespace std::chrono_literals;

    template <typename FSM>
    class Start;
    template <typename FSM>
    class Middle;
    template <typename FSM>
    class End;
    
    template <typename FSM>
    using TState =
        std::variant<Start<FSM>, Middle<FSM>, End<FSM>>;
    
    template <typename FSM>
    using TOptState = std::optional<TState<FSM>>;

    template <typename FSM>
    class TBaseState {
    public:
        explicit TBaseState(std::reference_wrapper<FSM> context) : _context(context) {
        }

        template <typename EventType>
        TOptState<FSM> process(EventType) {
            return TOptState<FSM>{};
        }

    protected:
        std::reference_wrapper<FSM> _context;
    };
    
    template <typename FSM>
    class Start : public TBaseState<FSM> {
    public:
        using TBaseState<FSM>::_context;
        explicit Start(std::reference_wrapper<FSM> context)
            : TBaseState<FSM>(context)
        {
        }

        std::string getState() const {
            return "Start";
        }

        using TBaseState<FSM>::process;
        TOptState<FSM> process(const UpdateEvent& event) {
            return Middle<FSM>(_context);
        }
    private:
    };

    template <typename FSM>
    class Middle : public TBaseState<FSM> {
    public:
        using TBaseState<FSM>::_context;
        explicit Middle(std::reference_wrapper<FSM> context)
            : TBaseState<FSM>(context)
        {
        }

        std::string getState() const {
            return "Middle";
        }

        using TBaseState<FSM>::process;
        TOptState<FSM> process(const UpdateEvent& event) {
            if (++m_NumIterations > 10)
            {
                event.m_Coro("Im in state Middle!");
                return End<FSM>(_context);
            }
            return std::nullopt;
        }
    private:
        uint8_t m_NumIterations {};
    };
    
    template <typename FSM>
    class End : public TBaseState<FSM> {
    public:
        using TBaseState<FSM>::_context;
        explicit End(std::reference_wrapper<FSM> context)
            : TBaseState<FSM>(context)
        {
        }

        std::string getState() const {
            return "End";
        }

        using TBaseState<FSM>::process;
        TOptState<FSM> process(const UpdateEvent& event) {
            return Start<FSM>(_context);
        }
    };

} // namespace states
