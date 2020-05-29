#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	char funcionario[30],funcao[30];
	int dependentes;
	float salarioBruto,inss,fgts,irff,salarioLiquido, valorParcial,pensao,refInss,refIrff,totalDesc;
	//entrada de dados
	cout<< "Favor cadastrar o funcionario"<< endl;
	system("Pause");	
	cout<< "Digite o nome do funcionario"<< endl;
	gets(funcionario);
	cout<< "Digite a funcao do funcionario "<< endl;
	gets(funcao);
	cout<< "Digite o salario do funcinario"<< endl;
	cin>>(salarioBruto);
	cout<< "Digite a quantidade de dependentes do funcionario"<< endl;
	cin>>(dependentes);
	cout<<"Este funcionario paga pensao alimenticia"<<endl<< "se sim digite o valor e se nao digite 0"<<endl;
	cin>>(pensao);
	// processamento
	fgts =  salarioBruto * 0.08;
	//calculo do inss
	if(salarioBruto<=1045){
		inss = salarioBruto*0.075;
		refInss = 07.5;
	}	
	else if(salarioBruto<=2089.60){
		valorParcial = (salarioBruto - 1045);
		inss = valorParcial*0.09 + 78.38;
		refInss = 09.00;	
	}
	else if(salarioBruto<=3134.40){
		valorParcial = (salarioBruto - 2089.60);
		inss = valorParcial*0.12 + 172.39;
		refInss = 12.00;		
	}
	else if(salarioBruto<=6101.06){
		valorParcial = (salarioBruto - 3134.40);
		inss = valorParcial*0.14 + 297.77;
		refInss = 14.00;		
	}	
	else{
		inss = 713.10;
		refInss = 14.00;
	}
	// calculo irff
	valorParcial = salarioBruto - inss - pensao - (189.59*dependentes);
	if(salarioBruto<=1903.98){
		irff = 0;
		refIrff = 0;
	}
	else if(valorParcial<=2826.65){
		irff = (valorParcial * 0.075)-142.80;
		refIrff = 7.5;
	}
	else if(valorParcial<=3751.05){
		irff = (valorParcial*0.15)- 354.80;
		refIrff = 15;
	}
	else if(valorParcial<=4664.68){
		irff = (valorParcial*0.225)-636.13;
		refIrff = 22.5;	
	}
	else{
		irff = (valorParcial*0.275)-869.36;
		refIrff = 27.5;
	}
	totalDesc = inss + irff;
	salarioLiquido = salarioBruto - inss - irff;
	//Saida de dados 
	cout<< funcionario<< "                       "<< funcao<<endl<<endl;
	cout<<"Codigo"<<"       DESCRICAO    "<<" REFERENCIA "<<"VENCIMENTOS  "<<"  DESCONTOS"<<endl;
	cout<< "101  "<<"	 Salario Bruto"<<"      |"<<"30 d  |"<<"   "<< salarioBruto<<endl;
	cout<< "973  "<<"	 Inss         "<<"      |"<<refInss<<"    |"<<"                 |"<<inss<<endl;
	cout<< "987  "<<"	 IRFF	       "<<"     |"<<refIrff<<"   |"<<"                 |"<<irff<<endl<<endl<<endl;
	cout<<"                   TOTAL BRUTO"<<"      "<< "TOTAL DE DESCONTO"<<endl;
	cout<<"                     "<<salarioBruto<<"            "<< totalDesc<<endl<<endl;
		cout<< "                    VALOR LIQUIDO   "<< salarioLiquido << endl<< endl;
	cout<<"Base calculo FGTS    "<<salarioBruto<<"          FGTS    "<< fgts << endl<<endl;

	system("Pause");
		
	return 0;
	

}
