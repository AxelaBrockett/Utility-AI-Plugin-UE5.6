# Utility-AI-Plugin-UE5.6
A plugin for Unreal Engine 5.6 that provides Utility AI logic and assets.

V1.0.0
- Original version

V1.0.1
- Moved "bUseConsiderationFactor" from Utility Action Base to Utility Data Asset

V1.0.2
- Add grouping comments

V1.1.0
- Moved to subscription system instead of instanced system with Utility Subsystem
- Exposed several Utility Component functions to Blueprints:
    - GetCurrentAction()
    - GetLastSuccessfulAction()
    - AbortCurrentAction()
    - PauseLogicWithActionDecision()
    - ShouldRestartLogicWhenResumingComponentLogic()
    - IsComponentRunningAsynchronously()
    - IsUsingParallelRequirementChecking()
    - ShouldRetryOnFailure()
    - IsUsingConsiderationFactor()
    - AttemptRetry()
- Add helper functions:
    - GetUtilitySubsystem()
    - GetUtilitySubsystemChecked()
    - GetMutableUtilitySubsystem()
    - GetMutableUtilitySubsystemChecked()
    - GetActionInstanceMemoryOfType()
    - GetMutableActionInstanceMemoryOfType()
    - GetDebugCallstackString()
    - UtilityVLOG()
    - StateTreeRunStatusToUtilityActionRunStatus()
    - CalculateAngleDifferenceDot()
- Reworked Action logic to not use cached owning components due to Actions only existing once now
- Reworked Action logic to always return the Action Run Status instead of storing it so that Actions can run for more than one componnt at once
- Implemented GetWorld() overrides into Actions, Requirements and Factors
- Added Initialize() and Deinitialize() to Actions to handle relevant logic instead of having separate functions
- Updated the debugger to only show one Action and its Requirements and Factors at once, allowing for iterating through Actions with debugger controls (shift + i)

V1.1.1
- Updated the helpers to have platform specific includes for the Platform Stack Walk
- Small bug fixes and bug prevention

V1.2.0
- Remove the UABUtilityComponent and swap dependencies and inputs from UABUtilityComponent to AController
    - This makes Actions available to players as well as AI
    - Component logic will be moved to the UUtilitySubsystem
- Added branch prediction helpers for optimisation
- Added available Action helpers:
    - BTTask_RunUtilityAction
    - BTTask_RunUtilityDataAsset
    - STTask_RunUtilityAction
    - STTask_RunUtilityDataAsset
- Added Requirements examples, both come from the fact that the system is now open to both AI and players
    - UABUtilityRequirement_IsAI
    - UABUtilityRequirement_IsPlayer
- Simplified the Instance Memory base class to have less possible conflicts
    - bNeedsTick and corresponding functions removed
    - Class now holds an EABUtilityActionRunStatus, bNeedsTick replaced with this enum being in the Running state
    - bTickableActionComplete and bSuccess removed from the base class, it will be in any child classes that require it
- ControllerSubscribed() and ControllerUnsubscribed() functions added as post-initilization functions to be run when a Controller subscribes or unsubscribes
- Callstack printing is no longer a setting in the plugin settings, it is a parameter defaulted to false when calling ABUtility::Helpers::UtilityVLOG()
