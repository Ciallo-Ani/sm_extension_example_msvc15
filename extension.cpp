#include "extension.h"

Demo g_Demo;
SMEXT_LINK(&g_Demo);

bool Demo::SDK_OnLoad(char* error, size_t maxlen, bool late)
{
	gamehelpers->ServerCommand("say Hello world!\n");

	return true;
}

void Demo::SDK_OnUnload()
{
	gamehelpers->ServerCommand("say bye!\n");
}

