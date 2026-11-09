using UnrealBuildTool;
using System.Collections.Generic;

public class VibraAltoTarget : TargetRules
{
	public VibraAltoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("VibraAlto");
	}
}
