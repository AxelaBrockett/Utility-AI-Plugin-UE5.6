// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "AITypes.h"

namespace ABUtility::Helpers::Requirements
{
	// Compare a left value to a right value using a comparison type
	bool CompareValues(const float Left, const float Right, const EGenericAICheck& ComparisonType);
}