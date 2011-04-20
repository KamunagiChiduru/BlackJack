#ifndef	GAME_BLACKJACK_CCARD_HPP
#define	GAME_BLACKJACK_CCARD_HPP

namespace Game{
namespace BlackJack{

	/**
	 *	トランプのカード.
	 *
	 *	@version	0.01
	 */
	class CCard{
		public:
			enum SUIT{
				SPADE= 0, 
				CLUB= 1, 
				HEART= 2, 
				DIAMOND= 3, 
			};
			explicit CCard(SUIT const& suit, int no);
			SUIT const& GetSuit() const;
			int GetNo() const;
			int GetPoint() const;
			bool operator == (CCard const& r) const;
			bool operator != (CCard const& r) const;
		
		private:
			/**
			 *	スート.
			 */
			SUIT _suit;
			
			/**
			 *	番号.
			 *	1～13
			 */
			int _no;
	};
	
	/**
	 *	コンストラクタ.
	 *
	 *	@since	0.01
	 *	@param	suit	スート
	 *	@param	no		番号
	 */
	inline
	CCard::CCard(SUIT const& suit, int no) : _suit(suit), _no(no){
	}
	
	/**
	 *	==演算子オーバーロード.
	 *
	 *	スートと番号が右辺と等しければtrue
	 *
	 *	@since	0.01
	 *	@param	r	右辺
	 *	@return	真理値
	 */
	inline
	bool CCard::operator == (CCard const& r) const{
		return (_suit == r._suit && _no == r._no);
	}
	
	/**
	 *	!=演算子オーバーロード.
	 *
	 *	スートか番号が右辺と等しくなければtrue
	 *
	 *	@since	0.01
	 *	@param	r	右辺
	 *	@return	真理値
	 */
	inline
	bool CCard::operator != (CCard const& r) const{
		return (_suit != r._suit || _no != r._no);
	}
	
	/**
	 *	スート.
	 *
	 *	@since	0.01
	 *	@return	スート
	 */
	inline
	CCard::SUIT const& CCard::GetSuit() const{
		return _suit;
	}
	
	/**
	 *	番号.
	 *
	 *	@since	0.01
	 *	@return	1～13
	 */
	inline
	int CCard::GetNo() const{
		return _no;
	}
	
	/**
	 *	カードの点.
	 *
	 *	@since	0.01
	 *	@return	1～11
	 */
	inline
	int CCard::GetPoint() const{
		return (_no > 10) ? 10 : _no;
	}

}
}

#endif	//	GAME_BLACKJACK_CCARD_HPP
