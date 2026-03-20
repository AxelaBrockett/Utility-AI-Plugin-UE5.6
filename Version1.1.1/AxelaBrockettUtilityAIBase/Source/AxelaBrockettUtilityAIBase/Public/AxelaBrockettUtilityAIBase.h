// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FAxelaBrockettUtilityAIBaseModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
