#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int nCmdShow)
{
	//モデルハンドル
	int modele1, anim_nutral, anim_run, attachidx, rootflm;
	//ランニングフラグ
	bool running = FALSE;
	float anim_totaltime, playertime = 0.0f;
	
	//KEYフラグ
	bool key = false;

	//モデルのポジション
	VECTOR pos = VGet(600.f, 300.0f, -400.0f);
	//カメラのポジション
	VECTOR cpos = VGet(600.0f, 600.0f, -400.0f), ctgt = VGet(600.0f, 300.0f, -400.0f);
	//列挙型
	enum Direction { DOWN, LEFT, UP, RIGHT }direction = DOWN;
	//マトリックス
	MATRIX mat1, mat2;

	//画面の設定
	ChangeWindowMode(TRUE);
	SetGraphMode(1200, 800, 32);

	//DxLidの初期化
	if (DxLib_Init() == -1)return -1;
	//モデルの読み込み
	modele1 = MV1LoadModel("../DxlibBasicSetting/3DCharacter/PC.mv1");
	//モデルの読み込み失敗
	if (modele1 == -1) return -1;
	//立ちアニメーションモデル読み込み
	anim_nutral = MV1LoadModel("../DxlibBasicSetting/3DCharacter/Anim_Neutral.mv1");
	if (anim_nutral == -1) { return -1; }
	//走るアニメーションモデル読み込み
	anim_run = MV1LoadModel("../DxlibBasicSetting/3DCharacter/Anim_Run.mv1");
	if (anim_run == -1) { return -1; }
	//モデルを設定
	attachidx = MV1AttachAnim(modele1, 0, anim_nutral);
	//アニメーションの総時間
	anim_totaltime = MV1GetAttachAnimTotalTime(modele1, attachidx);
	//フレームの読み込み
	rootflm = MV1SearchFrame(modele1, "root");
	MV1SetFrameUserLocalMatrix(modele1, rootflm, MGetIdent());

	SetDrawScreen(DX_SCREEN_BACK);

	//カメラの設定
	SetCameraPositionAndTargetAndUpVec(cpos, ctgt, VGet(0.0f, 0.0f, 1.0f));

	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) 
	{
		//アニメーション進行
		playertime += 0.5f;
		if (playertime > anim_totaltime) {playertime = 0.0f;}
		MV1SetAttachAnimTime(modele1, attachidx, playertime);
		key = CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_UP) ||
			CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT);

		//キーボードから入力
		if (CheckHitKey(KEY_INPUT_UP)) { pos.z += 4.0f; direction = UP; }
		if (CheckHitKey(KEY_INPUT_DOWN)) { pos.z -= 4.0f; direction = DOWN; }
		if (CheckHitKey(KEY_INPUT_LEFT)) { pos.x -= 4.0f; direction = LEFT; }
		if (CheckHitKey(KEY_INPUT_RIGHT)) { pos.x += 4.0f; direction = RIGHT; }
/*if (key == false) 
		{
			if (running) 
			{
				running = false;
				MV1DetachAnim(modele1, attachidx);
				attachidx = MV1AttachAnim(modele1, 0, anim_nutral);
				anim_totaltime = MV1GetAnimTotalTime(modele1, attachidx);
			}
			else
			{
				if (!running) 
				{
					running = true;
					MV1DetachAnim(modele1, attachidx);
					attachidx = MV1AttachAnim(modele1, 0, anim_run);
					anim_totaltime = MV1GetAnimTotalTime(modele1, attachidx);
				}
			}
		}*/
		
		if (key == false)
		{
			if (running)
			{
				running = false;
				MV1DetachAnim(modele1, attachidx);
				attachidx = MV1AttachAnim(modele1, 0, anim_nutral);
				anim_totaltime = MV1GetAttachAnimTotalTime(modele1, attachidx);
			}
		}

		else {
			if (!running)
			{
				running = true;
				MV1DetachAnim(modele1, attachidx);
				attachidx = MV1AttachAnim(modele1, 0, anim_run);
				anim_totaltime = MV1GetAttachAnimTotalTime(modele1, attachidx);
			}

		}
		//画面のクリア
		ClearDrawScreen();
	    //背景を描画
		DrawBox(0, 0, 1200, 800, GetColor(255, 255, 0), TRUE);

		//Y軸の回転行列をセットする
		//mat1 = MGetRotY(1.57f * direction);
		//平行移動行列をセットする
		//mat2 = MGetTranslate(pos);
		//モデルの座標返還行列をセットする
		//MV1SetMatrix(modele1,MMult(mat1, mat2));

		//回転関数を使いモデル
		MV1SetRotationXYZ(modele1,VGet(0.0f, 1.57f * direction, 0.0f));
		//3Dモデルのワールド座標を渡す
		MV1SetPosition(modele1, pos);
	    //3Dの描画
		MV1DrawModel(modele1);
  	    //画面の更新
		ScreenFlip();
	}
	
	//DxLibの終了

	DxLib_End();

	//プログラミングの終了
	return 0;

}