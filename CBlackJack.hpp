#ifndef	GAME_BLACKJACK_CBLACKJACK_HPP
#define	GAME_BLACKJACK_CBLACKJACK_HPP

#include <iostream>
#include "CDealer.hpp"
#include "CPlayer.hpp"
#include "CController.hpp"

namespace Game{
namespace BlackJack{

	/**
	 *	ブラックジャック、ゲームアルゴリズム実装クラス.
	 *
	 *	@version	0.01
	 */
	class CBlackJack{
		public:
			explicit CBlackJack();
			~CBlackJack();
			
			void Run();
		
		private:
			CDealer* _dealer;
			CPlayer* _player;
			CController* _controller;
	};
	
	/**
	 *	コンストラクタ.
	 *
	 *	@since	0.01
	 */
	CBlackJack::CBlackJack(){
		_dealer= new CDealer;
		_player= new CPlayer;
		_controller= new CController;
	}
	
	/**
	 *	デストラクタ.
	 *
	 *	@since	0.01
	 */
	CBlackJack::~CBlackJack(){
		delete _dealer;
		_dealer= NULL;
		
		delete _player;
		_player= NULL;
		
		delete _controller;
		_controller= NULL;
	}
	
	/**
	 *	メインループ.
	 *
	 *	@since	0.01
	 */
	void CBlackJack::Run(){
		bool player_burst, dealer_burst;
		
		do{
			player_burst= dealer_burst= false;
			_player->Clear();
			_dealer->Clear();
			_dealer->Shuffle();
			
			//	ベット
			//	ディール
			for(int i= 0; i < 2; ++i)
				_player->Add(_dealer->Hit());
			for(int i= 0; i < 2; ++i)
				_dealer->Add(_dealer->Hit());
			
			//	ディーラーのBJ確認
			if(_dealer->GetPoint() == 21){
				std::cout << "Dealer is BJ." << std::endl;
			}
			else{
				std::cout << "dealer's point is " << _dealer->GetPoint() << std::endl;
				std::cout << "player's point is " << _player->GetPoint() << std::endl;
				//	プレイヤのヒット
				while(!player_burst && _controller->Select(_T("hit"), _T("stand")) == 1){
					_player->Add(_dealer->Hit());
					std::cout << "player's point is " << _player->GetPoint() << std::endl;
					if(_player->GetPoint() > 21)
						player_burst= true;
				}
				//	ディーラーのヒット
				while(!player_burst && _dealer->GetPoint() < 17){
					_dealer->Add(_dealer->Hit());
					std::cout << "dealer's point is " << _dealer->GetPoint() << std::endl;
					if(_dealer->GetPoint() > 21)
						dealer_burst= true;
				}
			}
			//	精算
			if(player_burst || (!dealer_burst && _dealer->GetPoint() > _player->GetPoint()))
				std::cout << "dealer is won." << std::endl;
			else if(dealer_burst || (!player_burst && _dealer->GetPoint() < _player->GetPoint()))
				std::cout << "player is won." << std::endl;
			else
				std::cout << "drow." << std::endl;
		}while(_controller->Select(_T("replay"), _T("exit")) == 1);
	}

}
}

#endif	//	#ifndef	GAME_BLACKJACK_CBLACKJACK_HPP
