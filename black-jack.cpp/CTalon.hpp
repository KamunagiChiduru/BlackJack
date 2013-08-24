#ifndef	GAME_BLACKJACK_CTALON_HPP
#define	GAME_BLACKJACK_CTALON_HPP

#include "CCard.hpp"
#include "../Classes/CXorShift.hpp"

namespace Game{
namespace BlackJack{

	/**
	 *	ディーラーの持つ山札.
	 *
	 *	@version	0.01
	 */
	class CTalon{
		public:
			explicit CTalon();
			explicit CTalon(CTalon const& talon);
			~CTalon();
			
			CCard const& Hit();
			void Shuffle();
		
		private:
			CCard* _talon;
			Lib::CXorShift* _random;
			bool _rest[52];
			int _size;
	};
	
	/**
	 *	コンストラクタ.
	 *
	 *	@since	0.01
	 */
	CTalon::CTalon() : _size(0){
		_talon= (CCard*)malloc(sizeof(CCard) * 52);
		_random= new Lib::CXorShift;
		
		//	スペード
		for(int i= 1; i <= 13; ++i, ++_size)
			_talon[_size]= CCard(CCard::SPADE, i);
		
		//	クラブ
		for(int i= 1; i <= 13; ++i, ++_size)
			_talon[_size]= CCard(CCard::CLUB, i);
		
		//	ハート
		for(int i= 1; i <= 13; ++i, ++_size)
			_talon[_size]= CCard(CCard::SPADE, i);
		
		//	ダイア
		for(int i= 1; i <= 13; ++i, ++_size)
			_talon[_size]= CCard(CCard::SPADE, i);
		
		for(int i= 0; i < 52; ++i)
			_rest[i]= true;
		
		_ASSERT(_size == 52);
	}
	
	/**
	 *	コピーコンストラクタ.
	 *
	 *	@since	0.01
	 *	@param	talon	被コピーオブジェクト
	 */
	inline
	CTalon::CTalon(CTalon const& talon) : _size(talon._size){
		_talon= (CCard*)malloc(sizeof(CCard) * 52);
		_random= talon._random;
		
		for(int i= 0; i < 52; ++i){
			_talon[i]= talon._talon[i];
			_rest[i]= talon._rest[i];
		}
	}
	
	/**
	 *	デストラクタ.
	 *
	 *	@since	0.01
	 */
	inline
	CTalon::~CTalon(){
		free(_talon);
		_talon= NULL;
		
		delete _random;
		_random= NULL;
	}
	
	/**
	 *	ヒット.
	 *
	 *	@since	0.01
	 *	@return	引かれたカード
	 */
	inline
	CCard const& CTalon::Hit(){
		int idx;
		
		do{
			idx= _random->Generate(51);
		}while(!_rest[idx]);
		
		_rest[idx]= false;
		--_size;
		
		return _talon[idx];
	}
	
	/**
	 *	シャッフル.
	 *	山札をリセット.
	 *
	 *	@since	0.01
	 */
	inline
	void CTalon::Shuffle(){
		_size= 52;
		for(int i= 0; i < 52; ++i)
			_rest[i]= true;
	}

}
}

#endif	//	GAME_BLACKJACK_CTALON_HPP
