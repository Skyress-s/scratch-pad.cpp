#pragma once

// #include "ConditionalStream.h"
#include <functional>
#include <optional>

#include "FSM.h"
#include "States.h"
// #include "Turnstile.h"

namespace fsm_state_transitions {
    class FSM;

    using Start = states::Start<FSM>;
    using Middle = states::Middle<FSM>;
    using End = states::End<FSM>;
    using State = std::variant<Start, Middle, End>;
    using OptState = std::optional<State>;

    class FSM {
    public:
        FSM() : _fsm{Start{std::ref(*this)}}
        {

        }

        template <typename Event>
        FSM & process(Event event) {
            _fsm.process(std::move(event));
            return *this;
        }

        std::string getState() const {
            return _fsm.getState();
        }


    private:
        adc::TFSMStateTransitions<Start, Middle, End> _fsm;
    };

}