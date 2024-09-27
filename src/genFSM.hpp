#ifndef GENFSM_HPP
#define GENFSM_HPP

/*******************************************************************************
 *
 * @file   genFSM.hpp
 * @brief  Generic Finite State Machine (FSM) class definition
 * @author Parul Singh, Edward Speer
 * @date   9/27/2024
 *
 * This file defines a generic finite state machine (FSM) class.
 *******************************************************************************/

using namespace std;

/*******************************************************************************
 *
 * @class  State
 * @brief  A class representing a state in a finite state machine (FSM)
 *
 * This class represents a state in a finite state machine (FSM). Each state
 * has a label of user defined type Label_T and a transition function.
 *******************************************************************************/

template <typename Label_T>
class State
{
   private:
    Label_T label_;

   public:
    // ATTRIBUTES
    State (*transition_f)(void *);

    // CONSTRUCTORS
    State(Label_T label);
    State(Label_T label, State (*transition_f)(void *));

    // METHODS

    // GETTERS
    Label_T get_label();

    // SETTERS
    void set_transition_f(State (*transition_f)(void *));
};

#endif  // #ifndef GENFSM_HPP