#include "extension.h"

#ifdef _WINDOWS
#pragma comment(lib, "legacy_stdio_definitions.lib")
#endif

Demo g_Demo;
SMEXT_LINK(&g_Demo);
IGameEventManager2* eventmanager = NULL;

bool Demo::SDK_OnLoad(char* error, size_t maxlen, bool late)
{
	gamehelpers->ServerCommand("say Hello world!\n");
	eventmanager->AddListener(this, "player_death", false);

	return true;
}

void Demo::SDK_OnUnload()
{
	gamehelpers->ServerCommand("say bye!\n");
	eventmanager->RemoveListener(this);
}

bool Demo::SDK_OnMetamodLoad(ISmmAPI* ismm, char* error, size_t maxlen, bool late)
{
	GET_V_IFACE_CURRENT(GetEngineFactory, eventmanager, IGameEventManager2, INTERFACEVERSION_GAMEEVENTSMANAGER2);
}

void Demo::FireGameEvent(IGameEvent* event)
{
	char buffer[128];
	sprintf(buffer, "say firing event name-> %s\n", event->GetName());
	//gamehelpers->TextMsg(1, 3, buffer);
	gamehelpers->ServerCommand(buffer);
}