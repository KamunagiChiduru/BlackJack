#ifndef	GAME_BLACKJACK_CPLAYER_HPP
#define	GAME_BLACKJACK_CPLAYER_HPP

#include "CHand.hpp"

namespace Game{
namespace BlackJack{

	/**
	 *	プレイヤ.
	 *
	 *	@version	0.01
	 */
	class CPlayer{
		public:
			explicit CPlayer();
			~CPlayer();
			
			void Add(CCard const& card);
			void Clear();
			int GetPoint() const;
		
		protected:
			CHand* _hand;
	};
	
	/**
	 *	コンストラクタ.
	 *
	 *	@since	0.01
	 */
	inline
	CPlayer::CPlayer(){
		_hand= new CHand;
	}
	
	/**
	 *	デストラクタ.
	 *
	 *	@since	0.01
	 */
	inline
	CPlayer::~CPlayer(){
		delete _hand;
	}
	
	/**
	 *	手札にカード追加.
	 *
	 *	@since	0.01
	 *	@param	card	追加されるカード
	 */
	inline
	void CPlayer::Add(CCard const& card){
		_hand->Add(card);
	}
	
	/**
	 *	手札を空に.
	 *
	 *	@since	0.01
	 */
	inline
	void CPlayer::Clear(){
		_hand->Clear();
	}
	
	/**
	 *	手札の合計ポイント.
	 *
	 *	@since	0.01
	 *	@return	合計ポイント
	 */
	inline
	int CPlayer::GetPoint() const{
		return _hand->GetPoint();
	}

}
}

#endif	//	GAME_BLACKJACK_CPLAYER_HPP
