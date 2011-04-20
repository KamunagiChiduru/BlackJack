#ifndef	GAME_BLACKJACK_CCONTROLLER_HPP
#define	GAME_BLACKJACK_CCONTROLLER_HPP

#include <stdio.h>
#include <windows.h>

namespace Game{
namespace BlackJack{

	/**
	 *	ユーザからの入力処理用クラス.
	 *
	 *	@version	0.01
	 */
	class CController{
		public:
			void WaitKeyPressed(int key_code) const;
			bool IsKeyPressing(int key_code) const;
			int Select(_TCHAR const* mes1, _TCHAR const* mes2) const;
	};
	
	void CController::WaitKeyPressed(int key_code) const{
		char str[8];
		
		do{
			printf("press %c", key_code);
			scanf("%s", str);
		}while(str[0] != key_code);
	}
	
	int CController::Select(_TCHAR const* mes1, _TCHAR const* mes2) const{
		int selected;
		
		_tprintf(_T("select:\n1, %s\n2, %s\n"), mes1, mes2);
		_tscanf("%d", &selected);
		
		return selected;
	}
	
	/**
	 *	key_codeで指定されたキーが押されているかチェック.
	 *
	 *	@since	0.01
	 *	@param	key_code	チェック対象
	 *	@return	押されていればtrue
	 */
	inline
	bool CController::IsKeyPressing(int key_code) const{
		if(GetAsyncKeyState(key_code) & 0x8000)
			return true;
		else
			return false;
	}

}
}

#endif	//	GAME_BLACKJACK_CCONTROLLER_HPP
