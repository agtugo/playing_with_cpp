#include <iostream>
#include <concepts>
#include <boost/concept_check.hpp>

class IMotor {
	public:
		virtual ~IMotor() {};
		virtual int getValueP() = 0;
                virtual int getValueI() = 0;
		virtual int getValueD() = 0;
		virtual void setValueP(int p) = 0;
		virtual void setValueI(int i) = 0;
		virtual void setValueD(int d) = 0;
		
        protected:
		int p;
		int i;
		int d;
};

class MotorFast: public IMotor {
	public:
		int getValueP(){ 
			return p;
		}
		int getValueI(){
			return i;
		}
		int getValueD(){
			return d;
		}
		void setValueP(int p){
			this->p = p;
		}
		void setValueI(int i){
			this->i = i;
		}
		void setValueD(int d){
			this->d = d;
		}
};

template <typename T>
concept CMotor = requires(T &t)
{
        requires std::default_initializable<T>;
	{t.getValueP()} -> std::convertible_to<int>;
	{t.getValueI()} -> std::integral;
	{t.getValueD()} -> std::same_as<int>;
};

class MotorSlow{
	public:
		MotorSlow(int P = 0, int I = 0, int D = 0) :
			p(P),
			i(I),
			d(D) {}
		int getValueP() {return p;}
		int getValueI() {return i;}
		int getValueD() {return d;}
	private:
		int p;
		int i;
		int d;
};

void printPid(IMotor &motor){
	std::cout << "Motor info:"     << std::endl
		  << "P - "            << motor.getValueP() << std::endl
		  << "I - "            << motor.getValueI() << std::endl
		  << "D - "            << motor.getValueD() << std::endl;
}

template <typename T>
requires CMotor<T>
void printAnyPID(T &motor){
	std::cout << "Motor info:"     << std::endl
		  << "P - "            << motor.getValueP() << std::endl
		  << "I - "            << motor.getValueI() << std::endl
		  << "D - "            << motor.getValueD() << std::endl;
}
		

int main ()
{
	std::cout << "Hello world!\n";
	MotorFast myMotor = MotorFast();
	MotorSlow mySlowMotor = MotorSlow(1,2,3);
	myMotor.setValueP(5);
	myMotor.setValueI(7);
	myMotor.setValueD(11);
	printPid(myMotor);
	printAnyPID(myMotor);
	printAnyPID(mySlowMotor);
}
