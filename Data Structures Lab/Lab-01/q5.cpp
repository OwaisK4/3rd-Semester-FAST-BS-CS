#include <iostream>
using namespace std;

class Course{
	private:
		bool table[5][5] = {};
	public:
		Course(): table{{0,1,0,1,1}, 
						{1,0,1,0,1}, 
						{0,1,0,0,0}, 
						{1,0,0,0,1}, 
						{1,1,0,1,0} }{}
		bool SafeArray(int index1, int index2){
			if ((index1 >=0 && index1 < 5) && (index2 >=0 && index2 < 5))
				return true;
			else
				return false;
		}
		void set(int element, int index1, int index2){
			if (SafeArray(index1, index2))
				table[index1][index2] = element;
		}
		int get(int index1, int index2){
			if (SafeArray(index1, index2))
				return table[index1][index2];
		}
		void check(int student1, int student2){
			bool found = false;
			for (int i=0; i<5; i++){
				if (SafeArray(i, i)){
					if (table[i][student1] && table[i][student2]){
						found = true;
						cout << "Course-mate found! " << student1 << " and " << student2 << " have common course mate: " << i << "\n";
					}
				}
			}
			if (!found){
				cout << student1 << " and " << student2 << " have no common course mates." << "\n";
			}
			cout << "\n";
		}
		void Print(){
			for (int i=0; i<5; i++){
				for (int j=0; j<5; j++){
					if (SafeArray(i, j)){					
						cout << table[i][j] << " ";
					}
				}
				cout << "\n";
			}
			cout << "\n";
		}
		
};

int main(){
	Course course;
	course.Print();
	course.check(0,4);
	course.check(1,2);
	course.check(0,1);
	return 0;
}
