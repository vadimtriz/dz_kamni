#include<iostream>
#include<limits>
#include<random>

int main()
{
	setlocale(0, "rus");
	std::cout << "Игра \"Камни\". Правила: 2 игрока - пользователь и компьютер - делают ходы по очереди. \nЕсть куча, в ней N камней (N = 10..20 - выбирается случайным образом)\nЗа ход игрок обязан взять 1, 2 или 3 камня.\nКто забрал последний камень - проиграл." << std::endl;
	std::default_random_engine rnd;
		std::random_device rdev;
		rnd.seed(rdev());
		std::uniform_int_distribution<> stones {10,20};
		std::uniform_int_distribution<> stnes {1,3};
 retry:
		int N=stones(rnd);
		 while (N > 0)
		    {
		        int x;
		        int m=3;

		        std::cout <<"В куче "<< N << " камней" << std::endl;
		        do {
		        	menu_retry:
		            std::cout << "Ваш ход: " << std::endl;
		            if (not(std::cin>>x)){std::cout<<"Неккоректный ввод\nТребуется ввести число"<<std::endl;
		            	std::cin.clear();
		            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		            	goto menu_retry;}
		            } while (x <=0 || x>m || x>N);
		        N -= x;
		        std::cout << N << " камней в куче" << std::endl;
		        if (N == 0) {
		            std::cout << "Вы проиграли" << std::endl;
		        continue;
		        }
		        x = stnes(rnd) % m + 1;
		        if (x > N) x = N;
		        N -= x;
		        std::cout << "Мой ход: -" << x << std::endl;
		        std::cout << N << " камней в куче" << std::endl;
		        if (N == 0) {
		        	std::cout << "Компьютер проиграл" << std::endl;
		        	 continue;
		        }}

     	std::cout << "Играем снова?\n1 - да, 0 - нет" << std::endl;
     	int c;
     	std::cin>>c;
		if (c==1) goto retry;
     	if (c==0) std::cout << "До свидания!" << std::endl;


	return 0;
}

