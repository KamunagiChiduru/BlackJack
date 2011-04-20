#ifndef	GAME_BLACKJACK_CMENU_HPP
#define	GAME_BLACKJACK_CMENU_HPP

#include <iostream>
#include <vector>
#include <tchar.h>
#include "CController.hpp"

namespace Game{
namespace BlackJack{

	/**
	 *	メニュー画面.
	 *
	 *	@version	0.01
	 */
	class CMenu{
		public:
			~CMenu();
			
			void Add(int idx, _TCHAR const* description);
			void Remove(int idx);
			_TCHAR const* operator [] (int idx) const;
		
		protected:
			std::vector<_TCHAR*> _item;
	};
	
	CMenu::~CMenu(){
		for(int i= 0; i < _item.size(); ++i){
			free(_item[i]);
			_item[i]= NULL;
		}
	}
	
	void CMenu::Add(int idx, _TCHAR const* description){
		_item.insert(idx, _tcsdup(description));
	}
	
	_TCHAR const* operator [] (int idx) const{
		_ASSERT(idx >= 0 && idx < _item.size());
		if(idx >= 0 && idx < _item.size())
			return _item[idx];
		else
			return NULL;
	}

}
}

#endif	//	#ifndef	GAME_BLACKJACK_CMENU_HPP
