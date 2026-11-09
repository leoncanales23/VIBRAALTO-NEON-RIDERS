using UnrealBuildTool;
using System.Collections.Generic;

public class VibraAltoEditorTarget : TargetRules
{
	public VibraAltoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("VibraAlto");
	}
}
