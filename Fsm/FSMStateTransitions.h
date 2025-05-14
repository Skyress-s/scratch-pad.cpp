#pragma once

// #include "ConditionalStream.h"
#include <functional>
#include <optional>

#include "FSM.h"
// #include "States.h"
#include "StartState.h"
#include "EndState.h"

namespace fsm_state_transitions {
    class FSM;

    using Start = states::Start;
    using End = states::End;

    using State = std::variant<Start, End>;
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
        adc::TFSMStateTransitions<Start, End> _fsm;
    };

}