#include <iostream>

#include "FSM_impl.hpp"

State<int> state1(1);
State<int> state2(2);

State<int> transf_1(void *UNUSED)
{
    std::cout << "Transitioning from state 1 to state 2" << std::endl;
    return state2;
}

State<int> transf_2(void *UNUSED)
{
    std::cout << "Transitioning from state 2 to state 1" << std::endl;
    return state1;
}

State<int> transf_3(void *UNUSED)
{
    std::cout << "Transitioning from state 3 to state 1" << std::endl;
    return state1;
}

int main()
{
    std::cout << "State 1 label: " << state1.get_label() << std::endl;
    state1.set_transition_f(transf_1);

    std::cout << "State 2 label: " << state2.get_label() << std::endl;
    state2.set_transition_f(transf_2);

    State<int> curr_state = state1;
    std::cout << "Current state label: " << curr_state.get_label() << std::endl;

    curr_state = curr_state.transition_f(NULL);
    std::cout << "Current state label: " << curr_state.get_label() << std::endl;

    curr_state = curr_state.transition_f(NULL);
    std::cout << "Current state label: " << curr_state.get_label() << std::endl;

    State<int> state3(3, transf_3);
    std::cout << "State 3 label: " << state3.get_label() << std::endl;

    curr_state = state3;
    std::cout << "Current state label: " << curr_state.get_label() << std::endl;

    curr_state = curr_state.transition_f(NULL);
    std::cout << "Current state label: " << curr_state.get_label() << std::endl;

    return 0;
}