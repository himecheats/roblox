
#pragma once

#define oGameObjectManager 0x17A09A8 //0x17D69F8 новый //0x17C1F18 старый

#pragma region BasePlayer

#define oPlayerInput 0x4E0// public PlayerInput input;
#define oPlayerModel 0x4C0// public PlayerModel playerModel;
#define oPlayerFlags 0x650// public BasePlayer.PlayerFlags playerFlags;
#define oUserID 0x698// public ulong userID;
#define oDisplayName 0x6B0// protected string _displayName
#define oClientTickInterval 0x620// public float clientTickInterval;
#define oClActiveItem 0x5C8// private uint clActiveItem; 
#define oInventory 0x660// public PlayerInventory inventory;
#define oMovement 0x4E8// public BaseMovement movement;


#pragma endregion

//*** Projectile ***//

#define oThickness 0x2C// public float thickness;

	//*** TOD_Sky ***//

#define oInstances 0x0// private static List<TOD_Sky> instances;
#define oCycle 0x38// public TOD_CycleParameters Cycle;

	//*** TOD_CycleParameters ***//

#define OHour 0x10// public float Hour;

#pragma region PlayerWalkMovement

#define oGroundAngle 0xBC// private float groundAngle;
#define oGroundAngleNew 0xC0// private float groundAngleNew;
#define oGravityMultiplier 0x7C// public float gravityMultiplier;
#define oFlying 0x144// private bool flying;
#define oGravityMultiplierSwimming 0x80 // public float gravityMultiplierSwimming;


#pragma endregion

#pragma region ItemDefinition

#define oShortname 0x20// public string shortname;
#define odisplayname 0x28// public Translate.Phrase displayName;
#define oID 0x18// public int itemid;

#pragma endregion


		//*** Item ***//
#define oUID 0x28// public uint uid;
#define ItemDefinition 0x20// public ItemDefinition info;
#define oHeldEntity 0x98// private EntityRef heldEntity;

		//*** Player Model ***//

#define oSmoothVelocity 0x21C// private Vector3 newVelocity
#define oVisible 0x268// internal bool visible;

		//*** BaseProjectile ***//

#define oPrimaryMagazine 0x2B8// public BaseProjectile.Magazine primaryMagazine;

		//*** BaseNetworkable ***//

#define oNetworkable 0x50// public Networkable net;

		//*** HeldEntity ***//

#define oPunches 0x160// protected List<HeldEntity.PunchEntry> _punches;

		//*** Networkable ***//

#define oNetworkId 0x10//public uint ID;

		//*** PlayerAttack ***//

#define oAttack 0x18// public Attack attack;

		//*** Attack ***//

#define oHitID 0x2C// public uint hitID;
#define oHitPartID 0x64// public uint hitPartID;
#define oHitBone 0x30// public uint hitBone;  ? //HitInfo 
#define oHitMaterialID 0x68 // public uint hitMaterialID;
#define oPlayerAttack 0x18 // public PlayerAttack playerAttack;
#define oAttack 0x18 // public Attack attack;
#define oHitNormalWorld 0x4C // public Vector3 hitNormalWorld;


		//*** BaseCombatEntity ***//

#define oLifeState 0x21C// public BaseCombatEntity.LifeState lifestate; 
#define oHealth 0x224// private float _health;

	//*** PlayerInput ***//

#define oKeyFocus 0x94// private bool hasKeyFocus;
#define oBodyAngles 0x3C// private Vector3 bodyAngles;


				//***  ***//

#define oStancePenalty 0x31C //private float stancePenalty;
#define oAimconePenalty 0x320 //private float aimconePenalty;
#define oAimCone 0x6C8 //public float aimCone;
#define oHipAimCone 0x2EC //public float hipAimCone;
#define oAimconePenaltyPerShot 0x2F0 //public float aimconePenaltyPerShot;
#define oCorpsePlayerName 0x2C0// public string _playerName;

#define oRecoil 0x2D8 // public RecoilProperties recoil;
#define oRecoilYawMin 0x18 // public float recoilYawMin;
#define oRecoilYawMax 0x1C // public float recoilYawMax;
#define oRecoilPitchMin 0x20 // public float recoilPitchMin;
#define oRecoilPitchMax 0x24  // public float recoilPitchMax;
#define oADSScale 0x30 // public float ADSScale; 
#define oMovementPenalty 0x34 // public float movementPenalty;
#define oAutomatic 0x288 // public bool automatic;
#define oSuccessFraction 0x360 // public float successFraction;
#define oAttackReady 0x360 // protected bool attackReady;
#define oArrowBack 0x364 // private float arrowBack;
#define oHornOrigin 0x200 // public GameObject hornOrigin;
#define oAttackRadius 0x294 //public float attackRadius;
#define oBlockSprintOnAttack 0x299 //public bool blockSprintOnAttack;
#define oNewVelocity 0x21C // private Vector3 newVelocity;
#define oLastSentTickTime 0x624 // private float lastSentTickTime;
#define oClientTeam 0x598 // public PlayerTeam clientTeam
#define oRecoilAngles 0x64 // public Vector3 recoilAngles;
#define oInventory 0x660// public PlayerInventory inventory;
#define oFrozen 0x4C8 // public bool Frozen;
#define oClothingWaterSpeedBonus 0x728 // public float clothingWaterSpeedBonus;
#define oClothingAccuracyBonus 0x72C // public float clothingAccuracyBonus;
#define oClothingBlocksAiming 0x720 // public bool clothingBlocksAiming;
#define oClothingMoveSpeedReduction 0x724 // public float clothingMoveSpeedReduction;

// hooks
#define oisslepre 0x2213150    // public bool IsSleeping() { }
#define osleeper 0x1EA53B0   //public bool get_sleeping() { }

//#define oGetSleeping 0x1C26670 //
#define oSetSkinColor 0x80EBF0 // private void SetSkinColor(Color skinColor) { }
#define oGetSkinColor 0x4F2720 // internal Color GetSkinColor(float skinNumber) { } класс SkinSet
#define oUIAdminn 0x8FF180 //public bool IsVisible() { } //class AdminUI
#define oGetFlying 0x1EA5330 // public bool get_flying() { }
#define oSetFlying 0x1EA5430 //public void set_flying(bool value) { }
#define oSendProjectileAttack 0x404690 // public void SendProjectileAttack(PlayerProjectileAttack attack) { }
#define oCanAttack 0x3E9DE0 // public bool CanAttack() { }
//#define oCreateProjectile 0x72EF20// private Projectile CreateProjectile(string prefabPath, Vector3 pos, Vector3 forward, Vector3 velocity) { } (2)
#define oBlockSprint 0x3E91D0 // public virtual void BlockSprint(float duration = 0,2) { }
#define oGetSpeed 0x3F4F80 // public float GetSpeed(float running, float ducking) { }
#define oGetIndexedSpreadScalar 0x630E80 // public float GetIndexedSpreadScalar(int shotIndex, int maxShots) { }
#define oAntiAim 0x403FD0 //internal void SendClientTick() { }
#define oFakeCard 0x63D0C0 //public int get_accessLevel() { }
#define oAimConeUtil 0x8601D0 //public static Vector3 GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = True) { }
#define oClientInput 0x346790 //public virtual void ClientInput(InputState state, ModelState modelState) { }
#define oTodSky 0x11F1CD0 // public T GetComponent() { } public static TOD_Sky get_Instance() { }
#define oClosestPoint 0x7DBD90 //public Vector3 ClosestPoint(Vector3 position) { }
#define oKnockDoor 0xAD8CC0 //public void Menu_KnockDoor(BasePlayer player) { }
#define oServerRPC 0x7E5570 //public void ServerRPC(string funcName) { }
#define oSetSkinColor 0x80EBF0 //private void SetSkinColor(Color skinColor) { }
#define oGetSkinColor 0x4F2720 // internal Color GetSkinColor(float skinNumber) { } класс SkinSet
#define oAmbientMode 0x1952CA0//// public static void set_ambientMode(AmbientMode value) { }
#define oambientIntensit 0x1952BE0 //public static void set_ambientIntensity(float value) { }
#define oambientLight 0x1952C60 //public static void set_ambientLight(Color value) { }


// hooks scripts.json
#define oBaseNetworkable 0x307BEA0 // //BN Class$BaseNetworkable BaseNetworkable_c*
#define oSlideWalk 0x993230 // PlayerWalkMovement$$HandleRunning 0x896340// private void HandleRunning(ModelState state, bool wantsRun) { }
#define oConVar 0x307AB58 //ConVar_Graphics_c*  Class$ConVar.Graphics
#define oEulerAngles 0x1FC4250 // "Name": "UnityEngine.Transform$$get_eulerAngles"
#define oPosition 0x184A060 // //UnityEngine.Transform$$get_position
#define oRun 0x20DF480 //ConsoleSystem$$Run 