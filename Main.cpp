
# include <Siv3D.hpp>

void Main()
{

	// Set Window
	Window::SetTitle(L"HchanDB");
	Window::Resize(800, 800);

	// Data
	int x = 380, y = 900;
	int flag_hit = 0, flag_vat = 0;
	int diff;

	// Hit Zone
	const Rect HitZone(360, 600, 80, 100);

	// Asset
	TextureAsset::Register(L"fal", L"/10000");
	TextureAsset::Register(L"j", L"/10001");
	TextureAsset::Register(L"Hina", L"/10002");

	srand(time(NULL));

	// Main Loop
	while (System::Update())
	{
		// Battle Start
		if (Input::KeySpace.clicked && (900 <= y || y < -100)) {
			flag_hit = flag_vat = 0;
			x = 380;
			y = 300;
			diff = rand() % 25 + 1;
		}

		// Muda Swing
		else if (Input::KeySpace.clicked && !(Rect(x, y, 40).intersects(HitZone))) {
			flag_vat = 1;
		}

		// Hit
		else if (Input::KeySpace.clicked && Rect(x, y, 40).intersects(HitZone) && flag_vat == 0) {
			flag_hit = flag_vat = 1;
		}

		// Draw
		HitZone.draw(Palette::Yellow);
		TextureAsset(L"j").draw(300, 130);
		TextureAsset(L"fal").draw(x, y);
		TextureAsset(L"Hina").scale(2).draw(280, 600);
		
		// Syori
		if (y < 900 && flag_hit==0)y += diff;
		if (flag_hit == 1 && -100 <= y) {
			y -= 20;
			x -= 5;
		}

	}
}
