#ifndef	GAME_BLACKJACK_CDEALER_HPP
#define	GAME_BLACKJACK_CDEALER_HPP

#include "CTalon.hpp"
#include "CPlayer.hpp"

namespace Game{
namespace BlackJack{

	class CDealer : public CPlayer{
		public:
			explicit CDealer();
			~CDealer();
			
			CCard const& Hit();
			void Shuffle();
		
		private:
			CTalon* _talon;
	};
	
	CDealer::CDealer(){
		_talon= new CTalon;
	}
	
	CDealer::~CDealer(){
		delete _talon;
		_talon= NULL;
	}
	
	CCard const& CDealer::Hit(){
		return _talon->Hit();
	}
	
	void CDealer::Shuffle(){
		_talon->Shuffle();
	}

}
}

#endif	//	#ifndef	GAME_BLACKJACK_CDEALER_HPP
