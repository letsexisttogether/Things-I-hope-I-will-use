int menu_selector(string menuMessage)
{
	short arrowCounter = 1; // переменная для определения позиции стрелки; изначально на первом пункте
	while (1)
	{
		system("cls");
		short sentencesCounter = 0; // переменная, которая в цикле определяет количество пунктов меню
		for (size_t i = 0; i < menuMessage.size(); i++)
		{
			if (menuMessage[i] == '\n')							// наткнулись на следующий пункт меню 
				if (++sentencesCounter == arrowCounter) // увеличиваем количество пунктов меню и сравниваем с текущим положением стрелки
					cout << " <<";
			cout << menuMessage[i];
		}
		// переменная, которая считывает нажатую клавишу 
		char keyPressed = _getch(); ;
		// условия передвижения указательной стрелки
		if (keyPressed == 80) arrowCounter++;      // была нажата клавиша вниз - перестановка стрелки на следующий пункт 
		if (keyPressed == 72) arrowCounter--;      // была нажата клавиша вверх - перестановка стрелки на предыдущий пункт
		if (keyPressed == 13) return arrowCounter; // при нажатии Enter, возвращается выбраный пункт меню
		// условия выхода стрелки за границы
		if (arrowCounter < 1) arrowCounter = sentencesCounter; // нажата w при стрелке на первом пункте - стрелка на последнем пункте
		if (arrowCounter > sentencesCounter) arrowCounter = 1; // нажата s при стрелке на последнем пункте - стрелка на первом пункте
	}
}
