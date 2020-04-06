/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The header file of a instruction-button. It changes scene to instruction scene.
 */
#pragma once
#ifndef __INSTRUCTION_BTN__
#define __INSTRUCTION_BTN__

#include "Button.h"

class Instruction_btn : public Button
{
public:
    Instruction_btn();
    ~Instruction_btn();

    bool ButtonClick() override;
private:
    bool m_isClicked;
};
#endif/*Defined(__INSTRUCTION_BTN__)*/