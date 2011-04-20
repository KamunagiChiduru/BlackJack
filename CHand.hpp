#ifndef	GAME_BLACKJACK_CHAND_HPP
#define	GAME_BLACKJACK_CHAND_HPP

#include <iostream>
#include <vector>

namespace Game{
namespace BlackJack{

	/**
	 *	手札.
	 *
	 *	@version	0.01
	 */
	class CHand{
		public:
			int GetPoint() const;
			void Add(CCard const& card);
			void Clear();
		
		private:
			std::vector<CCard> _hand;
	};
	
	/**
	 *	手札に1枚追加.
	 *
	 *	@since	0.01
	 *	@param	card	追加するカード
	 */
	inline
	void CHand::Add(CCard const& card){
		_hand.push_back(card);
	}
	
	/**
	 *	手札の合計ポイント.
	 *
	 *	@since	0.01
	 *	@return	合計ポイント
	 */
	inline
	int CHand::GetPoint() const{
		int point, ace_count;
		
		point= 0;
		
		for(int i= 0; i < _hand.size(); ++i){
			point+= _hand[i].GetPoint();
		}
		
		return point;
	}
	
	/**
	 *	手札を空にする.
	 *
	 *	@since	0.01
	 */
	inline
	void CHand::Clear(){
		_hand.clear();
	}

}
}

#endif	//	GAME_BLACKJACK_CHAND_HPP
