#include "custom_elements.hpp"
#include <vector>

float dpi_scale = 1.f;
ImFont* icons = nullptr;
ImFont* big = nullptr;
ImFont* bigger = nullptr;



void MenuSteep() {
	ImGui::StyleColorsDark();

	CreateDirectoryA("C:\\NovazBesting", NULL);
	CreateDirectoryA("C:\\NovazBesting\\Sound", NULL);
	CreateDirectoryA("C:\\NovazBesting\\cfg", NULL);


	static int tab = 0;
	static int subtab = 0;

	auto flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 6.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::SetNextWindowSize({ 720,490 });
	ImGui::Begin("##menu", nullptr, flags);
	{
		ImDrawList* draw = ImGui::GetWindowDrawList();
		ImVec2 pos = ImGui::GetWindowPos();

		draw->AddRectFilled({ pos.x,pos.y }, { pos.x + 720,pos.y + 50 }, ImColor(19, 22, 26), 6.f, ImDrawCornerFlags_Top);
		draw->AddRectFilled({ pos.x ,pos.y + 50 }, { pos.x + 720,pos.y + 490 }, ImColor(25, 30, 35), 6.f, ImDrawCornerFlags_All);
		draw->AddRectFilled({ pos.x ,pos.y + 470 }, { pos.x + 720,pos.y + 490 }, ImColor(45, 50, 55), 6.f, ImDrawCornerFlags_Bot);

		draw->AddText({ pos.x + 710 - ImGui::CalcTextSize("NovazBesting - 2021 (c)").x,pos.y + 470 + 10 - ImGui::CalcTextSize("NovazBesting - 2021 (c)").y / 2 }, ImColor(250, 250, 250), "NovazBesting - 2021 (c)");

		ImGui::PushFont(bigger);
		ImGui::SetCursorPos({ 20,25 - ImGui::CalcTextSize("NovazBesting").y / 2 });
		ImGui::Text("NovazBesting");
		ImGui::PopFont();

		ImGui::SetCursorPos({ 200,0 });
		ImGui::BeginGroup();
		{
			if (Tab("0", "Aimbot", "pSlient", ImVec2(95, 50), tab == 0 ? true : false))
				tab = 0;
			ImGui::SameLine();
			if (Tab("1", "Visuals", "Resources", ImVec2(95, 50), tab == 1 ? true : false))
				tab = 1;
			ImGui::SameLine();
			if (Tab("2", "ActiveSlot", "Radar", ImVec2(95, 50), tab == 2 ? true : false))
				tab = 2;
			ImGui::SameLine();
			if (Tab("3", "Misc", "FakeAdmin", ImVec2(95, 50), tab == 3 ? true : false))//Miscellaneous
				tab = 3;
			ImGui::SameLine();
			if (Tab("4", "Configs", "Config", ImVec2(95, 50), tab == 4 ? true : false))
				tab = 4;
		}
		ImGui::EndGroup();

		ImGui::SetCursorPos({ 10,60 });
		ImGui::BeginGroup();
		{
			if (tab == 0)
			{

				if (SubTab("AimBot", ImVec2(150, 25), subtab == 0 ? true : false))
					subtab = 0;

				if (SubTab("pSlient", ImVec2(150, 25), subtab == 1 ? true : false))
					subtab = 1;


				if (SubTab("Weapon", ImVec2(150, 25), subtab == 2 ? true : false))
					subtab = 2;


				/*if (SubTab("Other", ImVec2(150, 25), subtab == 3 ? true : false))
					subtab = 3;*/


			}
			if (tab == 1)
			{
				if (SubTab("Esp", ImVec2(150, 25), subtab == 4 ? true : false))
					subtab = 4;

				if (SubTab("Resources", ImVec2(150, 25), subtab == 5 ? true : false))
					subtab = 5;

				/*if (SubTab("Other", ImVec2(150, 25), subtab == 6 ? true : false))
					subtab = 6;*/

				/*if (SubTab("Other Ext", ImVec2(150, 25), subtab == 7 ? true : false))
					subtab = 7;*/

			}
			if (tab == 2)
			{
				if (SubTab("Activeslot", ImVec2(150, 25), subtab == 8 ? true : false))
					subtab = 8;

				/*if (SubTab("Other", ImVec2(150, 25), subtab == 9 ? true : false))
					subtab = 9;*/
			}
			if (tab == 3)
			{
				if (SubTab("Miscellaneous", ImVec2(150, 25), subtab == 10 ? true : false))
					subtab = 10;
			}
			if (tab == 4)
			{
				if (SubTab("Config", ImVec2(150, 25), subtab == 11 ? true : false))
					subtab = 11;

				/*if (SubTab("Config", ImVec2(150, 25), subtab == 12 ? true : false))
					subtab = 12;*/
			}
		}
		ImGui::EndGroup();

		static bool checkboxbool = false;
		static int sliderint = 254;
		static int comboint = 1;
		static float coloredit[3] = { 0.f,0.f,0.f };

		ImGui::SetCursorPos({ 170,60 });
		ImGui::BeginGroup();
		{
			ImGui::BeginChild("items", { 530, 400 });
			{
				draw->AddRectFilled(ImGui::GetWindowPos(), { ImGui::GetWindowPos().x + 530,ImGui::GetWindowPos().y + 400 }, ImColor(30, 35, 40, 200), 8.f);

				ImGui::PushFont(big);
				ImGui::SetCursorPos({ 10,10 });
				ImGui::BeginGroup();
				{
					if (tab == 0)
					{
						if (subtab == 0)
						{
							ImGui::BeginChild("AimBot", ImVec2(381, 331), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								Checkbox("Activate", &Vars::AimBot::Activate);
								Hotkey("Aim Key", &Vars::AimBot::aimkey, ImVec2(150, 30));
								Checkbox("Body Aim", &Vars::AimBot::BodyAim);
								Checkbox("RCS standalone", &Vars::AimBot::Standalone);
								Checkbox("Recoil system control", &Vars::AimBot::RCS);
								//Checkbox("SilentHeli", &Vars::AimBot::SilentHeli);
								Checkbox("Visible check", &Vars::AimBot::VisibleCheck);
								Checkbox("Show ", &Vars::AimBot::DrawFov);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("", Vars::Color::Fov);
								Checkbox("Fill FOV", &Vars::Visuals::FillFov);
								ImGui::SliderFloat("Fov", &Vars::AimBot::Fov, 0, 400);
								ImGui::SliderFloat("Max Distance", &Vars::AimBot::Range, 0.f, 400.f);
								if (ImGui::Button("Novaz Discord"))
								{
									system("start https://discord.gg/Sw9RWKedG3");
								}
								ImGui::EndGroup();
							}
							ImGui::EndChild();
							
						}
						if (subtab == 1)
						{
							ImGui::BeginChild("AimBot pSilent", ImVec2(381, 331), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								Checkbox("Peek Assist", &Vars::Misc::PeekAssist); 
								Checkbox("Peek Assist Indicator", &Vars::Misc::PeekAssistIndicator);
								Checkbox("Auto Shoot", &Vars::AimBot::AutoShoot);
								Checkbox("pSilent", &Vars::AimBot::pSilent);
								Checkbox("Body", &Vars::AimBot::pBody);
								Checkbox("Draw pSilent Fov", &Vars::AimBot::DrawSilentFov);
								SliderFloat("Fov Psilent", &Vars::AimBot::SilentFov, 0, 400);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4(" ", Vars::Color::SilentFovColor);
								Checkbox("pSilent Clear Target", &Vars::AimBot::PSilentClear);

								if (Vars::AimBot::PSilentClear)
								{
									Hotkey(("PSilentClear Key"), &Vars::AimBot::Psilentclearkey, ImVec2(150, 30));
								}
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						if (subtab == 2)
						{
							ImGui::BeginChild("Weapon", ImVec2(381, 370), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								if (ImGui::BeginCombo("HitBox", "Select")) {
									ImGui::Checkbox("AlwaysHeadshot", &Vars::AimBot::AlwaysHeadshot);
									ImGui::Checkbox("Always Body", &Vars::AimBot::AlwaysBody);
									ImGui::Checkbox("RandomHitBox", &Vars::AimBot::randhitbox);
									ImGui::EndCombo();
								}
								Checkbox("Automatic", &Vars::Misc::Automatic);

								Checkbox("IgnoreTeam", &Vars::AimBot::IgnoreTeam);
								Checkbox("FatBullet", &Vars::AimBot::FatBullet);
								Checkbox("Splitter Furnase", &Vars::AimBot::mouse_move);
								Checkbox("RapidFire", &Vars::AimBot::RapidFire);
								Checkbox("CanHoldItem", &Vars::Misc::canHoldItems);
								Checkbox("LongNeck", &Vars::Misc::LongNeck);
								if (Vars::Misc::LongNeck)
								{
									Hotkey("LongNeck key", &Vars::Misc::LongNeckkey, ImVec2(150, 30));
								}
								Checkbox("NoRecoil", &Vars::Misc::NoRecoil);
								Checkbox("Zoom", &Vars::Misc::Zoom);
								if (Vars::Misc::Zoom)
								{
									ImGui::SliderFloat("Zoom value", &Vars::Misc::Zoomvalue, 40.f, 10.f);
									Hotkey("Zoom key", &Vars::Misc::Zoomkey, ImVec2(150, 30));
								}
								Checkbox("100% Eoka", &Vars::Misc::SuperEoka);
								Checkbox("ShotGunTochka", &Vars::Misc::ShotGunTochka);
								//Checkbox("SilentHeli", &Vars::AimBot::SilentHeli);
								Checkbox("Anti-Spread", &Vars::Misc::AntiSpread);
								Checkbox("SuperBow", &Vars::Misc::SuperBow);  //SuperBow
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						if (subtab == 3)
						{
							
						}

					}
					if (tab == 1)
					{
						if (subtab == 4)
						{
							ImGui::BeginChild("Players", ImVec2(381, 331), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::BeginGroup();
								Checkbox(u8"Enable player ESP", &Vars::Visuals::PlayerESP);
								if (ImGui::BeginCombo("Player box", "Chose style box"))
								{
									Checkbox("Corner", &Vars::Visuals::boxxuina);
									Checkbox("Default", &Vars::Visuals::ShowPlayerBox);
									End();
								}
								ImGui::SameLine();
								ImGui::ColorEdit4("", Vars::Color::BoxColor);
								Checkbox(u8"FillBox", &Vars::Visuals::FillBox);

								static bool enabled = true;
								BoneList Bones[15] = {
									/*LF*/l_foot, l_knee, l_hip,
									/*RF*/r_foot, r_knee, r_hip,
									/*BD*/spine1, neck, head,
									/*LH*/l_upperarm, l_forearm, l_hand,
									/*RH*/r_upperarm, r_forearm, r_hand
								}; Vector2 BonesPos[15];
								ImGui::SetNextWindowSize(ImVec2(230, 400));
								ImVec2 menu_pos;
								float menu_size;
								menu_pos = ImGui::GetWindowPos();
								ImGui::SetNextWindowPos(ImVec2(menu_pos.x + menu_size - 4, menu_pos.y - 16));
								ImGui::Begin("ESP Preview", &enabled, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize);
								{
									ImGui::Text("                            ESP Preview");
									auto cur_window = ImGui::GetCurrentWindow();
									ImVec2 w_pos = cur_window->Pos;
									if (Vars::Visuals::Box)
									{
										cur_window->DrawList->AddRect(ImVec2(w_pos.x + 40, w_pos.y + 60), ImVec2(w_pos.x + 190, w_pos.y + 350), ImColor(Vars::Color::BoxColor));
									}
									if (Vars::Visuals::Name)
									{
										cur_window->DrawList->AddText(ImVec2{ w_pos.x + 80, w_pos.y + 40 }, ImColor(Vars::Color::NameColor), "! Mr.Yasin#7041");
									}
									if (Vars::Visuals::Dist)
									{
										cur_window->DrawList->AddText(ImVec2{ w_pos.x + 121, w_pos.y + 41 }, ImColor(Vars::Color::NameColor), "");
									}
									if (Vars::Visuals::Weapon)
									{
										cur_window->DrawList->AddText(ImVec2{ w_pos.x + 80, w_pos.y + 359 }, ImColor(Vars::Color::WeaponColor), "M249");
									}
									if (Vars::Visuals::healthbarpreviw)
									{
										cur_window->DrawList->AddRectFilled(ImVec2(w_pos.x + 35, w_pos.y + 60), ImVec2(w_pos.x + 37, w_pos.y + 350), ImColor(Vars::Color::helfbarcolorpreviw));
									}
								}
								ImGui::End();

								Checkbox(u8"ChamsSkin", &Vars::Visuals::Chams);
								Checkbox("Show Name", &Vars::Visuals::ShowPlayerName);
								ImGui::SameLine();
								ImGui::ColorEdit4(" ", Vars::Color::NameColor);
								Checkbox(u8"Health", &Vars::Visuals::ShowPlayerHealth);
								Checkbox(u8"Weapon", &Vars::Visuals::ShowPlayerWeapon);
								ImGui::SameLine();
								ImGui::ColorEdit4("  ", Vars::Color::WeaponColor);
								Checkbox(u8"Distance", &Vars::Visuals::ShowPlayerDist);
								Checkbox(u8"Ignore sleepers", &Vars::Visuals::IgnoreSleepers);
								Checkbox(u8"Skeleton", &Vars::Visuals::SkeletonPlayer);
								ImGui::SameLine();
								ImGui::ColorEdit4("   ", Vars::Color::SkeletonColor);
								ImGui::Text(u8"Bot");
								Checkbox(u8"BotsBoxes", &Vars::BotsEsp::BotsBoxes);
								Checkbox(u8"enable bots skeleton", &Vars::Visuals::SkeletonBots);
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						if (subtab == 5)
						{
							ImGui::BeginChild("World", ImVec2(400, 370), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								Checkbox(u8"Sulphur", &Vars::Visuals::Sulphur);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("", Vars::Color::SulfurEsp);
								if (Vars::Visuals::Sulphur)
								{
									ImGui::SliderFloat(u8"SulphurDistation", &Vars::Visuals::SulphurOreDistation, 0.f, 400.f);
								}
								Checkbox(u8"Metal", &Vars::Visuals::Metal);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4(" ", Vars::Color::MetalEsp);
								if (Vars::Visuals::Metal)
								{
									ImGui::SliderFloat(u8"MetalDistation", &Vars::Visuals::MetalOreDistation, 0.f, 400.f);
								}
								Checkbox(u8"Stone", &Vars::Visuals::Stone);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("  ", Vars::Color::StoneEsp);
								if (Vars::Visuals::Stone)
								{
									ImGui::SliderFloat(u8"StoneDistation", &Vars::Visuals::StoneOreDistation, 0.f, 400.f);
								}
								Checkbox(u8"Show Weapons", &Vars::Visuals::show_Weapons);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("   ", Vars::Color::show_WeaponsEsp);
								if (Vars::Visuals::show_Weapons)
								{
									ImGui::SliderFloat(u8"WeaponsDist", &Vars::Visuals::show_WeaponsDistation, 0.f, 400.f);
								}
								Checkbox(u8"Tank", &Vars::Visuals::Bradley);
								if (Vars::Visuals::Bradley)
								{
									ImGui::SliderFloat(u8"BradleyDist", &Vars::Visuals::BradleyDistation, 0.f, 400.f);
								}
								Checkbox(u8"Stash", &Vars::Visuals::Stash);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("    ", Vars::Color::StashEsp);
								if (Vars::Visuals::Stash)
								{
									ImGui::SliderFloat(u8"StashDist", &Vars::Visuals::StashDistation, 0.f, 400.f);
								}
								Checkbox(u8"Minicopter", &Vars::Visuals::Minicopter);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("     ", Vars::Color::MinicopterEsp);
								if (Vars::Visuals::Minicopter)
								{
									ImGui::SliderFloat(u8"MinicopterDist", &Vars::Visuals::MinicopterDistation, 0.f, 4000.f);
								}
								Checkbox(u8"Patrol Helicopter", &Vars::Visuals::Patrul);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("      ", Vars::Color::PatrulEsp);
								if (Vars::Visuals::Patrul)
								{
									ImGui::SliderFloat(u8"PatrulDist", &Vars::Visuals::PatrulDistation, 0.f, 4000.f);
									ImGui::Checkbox("HealthBar", &Vars::Visuals::ShowPlayerHealthBar1);
								}
								Checkbox("Traps", &Vars::Visuals::Traps);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("       ", Vars::Color::TrapsEsp);
								if (Vars::Visuals::Traps)
								{
									ImGui::SliderFloat(u8"TrapsDist", &Vars::Visuals::TrapsDistation, 0.f, 400.f);
								}
								Checkbox("Hemp", &Vars::Visuals::Hemp);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("        ", Vars::Color::HempEsp);
								if (Vars::Visuals::Hemp)
								{
									ImGui::SliderFloat("HempDist", &Vars::Visuals::HempDistation, 0.f, 400.f);
								}
								Checkbox(u8"Сupboard", &Vars::Visuals::Shkaf);
								if (Vars::Visuals::Shkaf)
								{
									ImGui::SliderFloat("СupboardDist", &Vars::Visuals::ShkafDIST, 0.f, 400.f);
								}
								Checkbox(u8"Grib", &Vars::Visuals::Mushrooms);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("         ", Vars::Color::Mushrooms);
								if (Vars::Visuals::Mushrooms)
								{
									ImGui::SliderFloat("MushroomsDist", &Vars::Visuals::MushroomsDistation, 0.f, 400.f);
								}
								Checkbox("Supply", &Vars::Visuals::Supply);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("          ", Vars::Color::SupplyEsp);
								if (Vars::Visuals::Supply)
								{
									ImGui::SliderFloat("SupplyDistation", &Vars::Visuals::SupplyDistation, 0.f, 4000.f);
								}
								Checkbox("Corpse", &Vars::Visuals::Corpse);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("           ", Vars::Color::CorpseEsp);
								if (Vars::Visuals::Corpse)
								{
									ImGui::SliderFloat("CorpseDistation", &Vars::Visuals::CorpseDistation, 0.f, 400.f);
								}

								ImGui::Checkbox("Loot box", &Vars::Visuals::normalbox2);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("            ", Vars::Color::normalbox2);

								ImGui::Checkbox("Military box", &Vars::Visuals::normalbox);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("             ", Vars::Color::normalbox);

								ImGui::Checkbox("Food box", &Vars::Visuals::food);
								ImGui::SameLine();
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("              ", Vars::Color::food);
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::Checkbox("Medical Box", &Vars::Visuals::medicalbox);
								ImGui::SameLine();
								ImGui::ColorEdit4("               ", Vars::Color::medicalbox);
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::Checkbox("Tool box", &Vars::Visuals::toolbox);
								ImGui::SameLine();
								ImGui::ColorEdit4("                ", Vars::Color::toolbox);
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::Checkbox("Mine box", &Vars::Visuals::mine);
								ImGui::SameLine();
								ImGui::ColorEdit4("                ", Vars::Color::mine);
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::Checkbox("Elite box", &Vars::Visuals::elite);
								ImGui::SameLine();
								ImGui::ColorEdit4("                  ", Vars::Color::elite);
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						if (subtab == 6)
						{

						}
						if (subtab == 7)
						{

						}

					}
					if (tab == 2)
					{
						if (subtab == 8)
						{
							ImGui::BeginChild("Radar##1", ImVec2(381, 331), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								{
									/*Checkbox(("Show Player Active Slot"), &Vars::Radar::ActiveSlot);
									ImGui::Text("Color");
									ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
									ImGui::ColorEdit4("Name", Vars::Color::Name);
									ImGui::ColorEdit4("====", Vars::Color::unactiv);
									ImGui::ColorEdit4("Line", Vars::Color::Line);
									ImGui::ColorEdit4("Weapon", Vars::Color::weaponactivslot);


									ImGui::Text(u8"Radar");
									ImGui::Checkbox("Enable", &Vars::Radar::Enable);
									ImGui::Checkbox("ShowRadarPlayer", &Vars::Radar::ShowRadarPlayer);
									ImGui::Checkbox("ShowRadarSleeper", &Vars::Radar::ShowRadarSleeper);
									ImGui::SliderFloat("Radar_Size", &Vars::Radar::Radar_Size, 0.f, 250.f);
									ImGui::SliderFloat("Radar_Range", &Vars::Radar::Radar_Range, 0.f, 300.f);*/
								}
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						if (subtab == 9)
						{

						}
						

					}
					if (tab == 3)
					{
						if (subtab == 10)
						{
							ImGui::BeginChild("Movement", ImVec2(381, 370), false, ImGuiWindowFlags_NoBackground);
							{
								ImGui::BeginGroup();
								Checkbox("Slide Walk", &Vars::Misc::SlideWalk);
								Checkbox("NoPlayerCollision", &Vars::Misc::no_playercollision);
								Checkbox("SwimOnGround", &Vars::Misc::SwimOnGround);
								Checkbox("SilentWalk", &Vars::Misc::SilentWalk);
								Checkbox("Wake Up sleepers", &Vars::Misc::issleepers);
								Checkbox("SpiderMan", &Vars::Misc::SpiderMan);
								Checkbox("Anti Aim", &Vars::Misc::AntiAim);
								Checkbox("Anti Afk", &Vars::Misc::Antiafk);
								Checkbox("WaterBoost", &Vars::Misc::WaterBoost);
								Checkbox("InfinityJump", &Vars::Misc::InfinityJump);
								Checkbox("FastBullets", &Vars::AimBot::FastBullet);
								if (Vars::AimBot::FastBullet)
								{
									ImGui::SliderFloat("BulletSpeed", &Vars::AimBot::SpeedBullets, 1.f, 3.f);
								}
								Checkbox("Change Gravity", &Vars::Misc::HighJump);
								Checkbox("JumpAiming", &Vars::Misc::JumpAiming);
								if (Vars::Misc::HighJump)
								{
									ImGui::SliderFloat("Gravity percentage", &Vars::Misc::JumpValue, 0.f, 2.5f);
									Hotkey("Gravity Key", &Vars::Misc::highkey, ImVec2(150, 30));
								}
								Checkbox("TimeScale", &Vars::Misc::SpeedHack);
								if (Vars::Misc::SpeedHack)
								{
									Hotkey("TimeScale key", &Vars::Misc::TimeScalekey, ImVec2(150, 30));
								}
								if (ImGui::BeginCombo("Crosshairs", "Select"))
								{
									ImGui::Checkbox("Collapse", &Vars::Visuals::Collapse);
									ImGui::Checkbox("CollapsSmall", &Vars::Visuals::Colapse1);
									ImGui::Checkbox(u8"Circle", &Vars::Visuals::CircleCrosshair);
									ImGui::Checkbox(u8"RainBow", &Vars::Visuals::Crosshair);
									ImGui::Checkbox(u8"Swastica", &Vars::Visuals::SEXXCrosshair);
									ImGui::EndCombo();
								}
								ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Crosshairs Color", Vars::Color::CollapseColor);
								Checkbox("AutoPickUp", &Vars::Misc::AutoPickUp);
								Checkbox("Door", &Vars::Misc::Door);
								Checkbox("Fake Lag", &Vars::Misc::FakeLag);
								Checkbox("Fake admin", &Vars::Misc::FakeAdmin);
								Checkbox("Fast Heal", &Vars::Misc::FastHeal);
								Checkbox("ThirdPerson", &Vars::Misc::ThirdPersone);
								Checkbox("DebugBypass", &Vars::Misc::DebugBypass);
								Checkbox("Frozen(mouse4)", &Vars::Misc::AirStuck);
								Checkbox("WorkBeanch", &Vars::Misc::WorkBench);
								Checkbox("Long Hand", &Vars::Misc::LongHand);
								Checkbox("Custom fov", &Vars::Misc::CustomFov);
								if (Vars::Misc::CustomFov)
								{
									ImGui::SliderFloat("fov", &Vars::Misc::GraphicsFov, 0.f, 180.f);
								}
								Checkbox("RGB mode", &Vars::Misc::rainbow);
								if (Vars::Misc::rainbow)
								{
									ImGui::SliderFloat("Speed RGB", &Vars::Misc::time, 0.f, 10.f);
								}
								Checkbox("Unlock aiming in heavy", &Vars::Misc::AntiKastrulya);
								Checkbox("Custom Time", &Vars::Misc::CustomTime);
								if (Vars::Misc::CustomTime)
								{
									ImGui::SliderFloat("Time", &Vars::Misc::Time, 0.f, 12.f);
								}
								Checkbox("NightMode", &Vars::Visuals::NightMode);
								ImGui::EndGroup();
							}
							ImGui::EndChild();
						}
						


					}
					if (tab == 4)
					{
						if (subtab == 11)
						{
							ImGui::BeginChild("Configurations", ImVec2(396, 426));
							{
								ImGui::SetCursorPos(ImVec2(15, 0));
								ImGui::BeginChild("Configurations##1", ImVec2(381, 331), false, ImGuiWindowFlags_NoBackground);
								{
									ImGui::BeginGroup();
									TextEx(("Config Name"));
									InputText((""), Vars::Global::ConfigName, 0x100);
									if (Button(("Save Config"), ImVec2(100.f, 0)))
										SaveCFG(Vars::Global::ConfigName);
									ImGui::SameLine();
									if (Button(("Load Config"), ImVec2(100.f, 0)))
										LoadCFG(Vars::Global::ConfigName);
									ImGui::EndGroup();

									ImGui::Text("Config 2");
									Checkbox("Rage cfg", &Vars::CFG::n1ntendo);
									ImGui::BeginGroup();
									if (Vars::CFG::n1ntendo) {
										GUI::Render.String({ 10.f, 10.f }, L"Rage config loaded..", D2D1::ColorF::Red);
										Vars::AimBot::pSilent = true;
										Vars::Visuals::PlayerESP = true;
										Vars::AimBot::AlwaysHeadshot = true;
										Vars::AimBot::FatBullet = true;
										Vars::Visuals::boxxuina = true;
										Vars::Visuals::ShowPlayerName = true;
										Vars::Visuals::ShowPlayerHealth = true;
										Vars::Visuals::ShowPlayerWeapon = true;
										Vars::Visuals::ShowPlayerDist = true;
										Vars::Visuals::IgnoreSleepers = true;
										Vars::Visuals::AlwaysDay = true;
										Vars::Visuals::BotsESP = true;
										Vars::Visuals::SkeletonBots = true;
										Vars::Visuals::Collapse = true;
										Vars::Misc::JumpAiming = true;
										Vars::Misc::FakeAdmin = true;
										Vars::Visuals::NightMode = true;
										Vars::Misc::SpiderMan = true;
										Vars::Radar::ActiveSlot = true;
										Vars::Misc::SuperEoka = true;
										Vars::Misc::ShotGunTochka = true;
										Vars::Misc::SlideWalk = true;
										ImGui::EndGroup();
									}

									Checkbox("Legit cfg", &Vars::CFG::n1ntendolegit);
									ImGui::BeginGroup();
									if (Vars::CFG::n1ntendolegit) {
										GUI::Render.String({ 10.f, 10.f }, L"Legit config loaded..", D2D1::ColorF::Red);
										Vars::AimBot::Activate = true;
										Vars::Visuals::Chams = true;
										Vars::Visuals::PlayerESP = true;
										Vars::AimBot::RCS = true;
										Vars::Misc::SlideWalk = true;
										Vars::Misc::JumpAiming = true;
										Vars::Visuals::Colapse1 = true;
										Vars::Radar::ActiveSlot = true;
										Vars::Visuals::NightMode = true;
										Vars::Visuals::BotsESP = true;
										Vars::Visuals::SkeletonBots = true;
										Vars::Visuals::boxxuina = true;
										Vars::Visuals::ShowPlayerName = true;
										Vars::Visuals::ShowPlayerHealth = true;
										Vars::Visuals::ShowPlayerWeapon = true;
										Vars::Visuals::ShowPlayerDist = true;
										Vars::Visuals::IgnoreSleepers = true;
										Vars::Misc::SpiderMan = true;
										ImGui::EndGroup();
									}

									Checkbox("Reset", &Vars::CFG::SBROSCFGBYFe1zep);
									ImGui::BeginGroup();
									if (Vars::CFG::SBROSCFGBYFe1zep) {
										GUI::Render.String({ 10.f, 10.f }, L"Rage config loaded..", D2D1::ColorF::Red);
										Vars::AimBot::pSilent = false;
										Vars::AimBot::PSilentTarget = false;
										Vars::AimBot::DrawPSilentFov = false;
										Vars::AimBot::AlwaysHeadshot = false;
										Vars::Visuals::ShowPlayerBox = false;
										Vars::Misc::CustomFov = false;
										Vars::AimBot::Activate = false;
										Vars::Visuals::PlayerESP = false;
										Vars::Visuals::ShowPlayerName = false;
										Vars::Visuals::ShowPlayerHealth = false;
										Vars::Visuals::ShowPlayerWeapon = false;
										Vars::Visuals::ShowPlayerDist = false;
										Vars::Visuals::IgnoreSleepers = false;
										Vars::Visuals::AlwaysDay = false;
										Vars::Visuals::Chams = false;
										Vars::Visuals::Crosshair = false;
										Vars::Misc::JumpAiming = false;
										Vars::Misc::SpiderMan = false;
										Vars::Misc::Automatic = false;
										Vars::Misc::SuperEoka = false;
										Vars::Misc::InfinityJump = false;
										Vars::Misc::SlideWalk = false;
										Vars::Misc::FastHeal = false;
										Vars::AimBot::pSilent = false;
										Vars::Visuals::PlayerESP = false;
										Vars::AimBot::AlwaysHeadshot = false;
										Vars::Visuals::ShowPlayerBox = false;
										Vars::Visuals::ShowPlayerName = false;
										Vars::Visuals::ShowPlayerHealth = false;
										Vars::Visuals::ShowPlayerWeapon = false;
										Vars::Visuals::ShowPlayerDist = false;
										Vars::Visuals::IgnoreSleepers = false;
										Vars::Visuals::AlwaysDay = false;
										Vars::Visuals::BotsESP = false;
										Vars::Visuals::SkeletonBots = false;
										Vars::Visuals::Collapse = false;
										Vars::Misc::JumpAiming = false;
										Vars::Misc::FakeAdmin = false;
										Vars::Visuals::NightMode = false;
										Vars::Misc::SpiderMan = false;
										Vars::Radar::ActiveSlot = false;
										Vars::Misc::SuperEoka = false;
										Vars::Misc::ShotGunTochka = false;
										Vars::Misc::SlideWalk = false;
										ImGui::EndGroup();
									}

									if (ImGui::Button("Novaz Discord"))
									{
										system("start https://discord.gg/Sw9RWKedG3");
									}
									ImGui::Text("Panic key (END)");
									ImGui::EndGroup();
								}
								ImGui::EndChild();
							}
							ImGui::EndChild();
						}
						if (subtab == 12)
						{

						}


					}
				}
				ImGui::EndGroup();
				ImGui::PopFont();
			}
			ImGui::EndChild();
		}
		ImGui::EndGroup();
		}
		ImGui::End();
		ImGui::PopStyleVar(3);
}
