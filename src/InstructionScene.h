#pragma once
#include "Scene.h"
#include "Instruction.h"
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__
class InstructionScene:public Scene
{
public:
	InstructionScene();
	~InstructionScene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
private:
	Instruction* m_pInstruction;
};
#endif/*Defined (__INSTRUCTION_SCENE__)*/