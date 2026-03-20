// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Helpers/ABUtilityHelpers.h"

namespace ABUtility::Helpers::Requirements
{
	bool CompareValues(const float Left, const float Right, const EGenericAICheck& ComparisonType)
	{
		switch (ComparisonType)
		{
			case (EGenericAICheck::Equal):
			{
				return Left == Right;
				break;
			}
			case (EGenericAICheck::NotEqual):
			{
				return Left != Right;
				break;
			}
			case (EGenericAICheck::Less):
			{
				return Left < Right;
				break;
			}
			case (EGenericAICheck::LessOrEqual):
			{
				return Left <= Right;
				break;
			}
			case (EGenericAICheck::Greater):
			{
				return Left > Right;
				break;
			}
			case (EGenericAICheck::GreaterOrEqual):
			{
				return Left >= Right;
				break;
			}
			default:
			{
				ensureAlwaysMsgf(false, TEXT("Unhandled Comparison Type [ %d ]."), ComparisonType);
				return false;
				break;
			}
		}
	}
}