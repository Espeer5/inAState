/*******************************************************************************
 *
 * @file: FSM_impl.hpp
 * @brief: Implementation of the generic finite state machine (FSM) template
 *         class
 * @author Parul Singh, Edward Speer
 * @date: 9/27/2024
 *
 * This file contains the implementation of the generic finite state machine
 * (FSM) template class.
 *******************************************************************************/

#include "genFSM.hpp"

/*******************************************************************************
 *
 * @class  State
 * @brief  A class representing a state in a finite state machine (FSM)
 *
 * This class represents a state in a finite state machine (FSM). Each state
 * has a label of user defined type Label_T and a transition function.
 *******************************************************************************/

// CONSTRUCTORS
template <typename Label_T>
State<Label_T>::State(Label_T label)
{
    label_ = label;
}

template <typename Label_T>
State<Label_T>::State(Label_T label, State (*transition_f)(void *))
{
    this->label_ = label;
    this->transition_f = transition_f;
}

// METHODS

template <typename Label_T>
Label_T State<Label_T>::get_label()
{
    return this->label_;
}

template <typename Label_T>
void State<Label_T>::set_transition_f(State (*transition_f)(void *))
{
    this->transition_f = transition_f;
}
