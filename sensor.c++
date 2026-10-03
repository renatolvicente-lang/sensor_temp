// C++ code
//Receber o dado do sensor converter para graus e 
//depois exibi-lo no terminal a cada 2s
#define sensorTemp A0

int vlrSensor;
int temp;
int temporizador;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorTemp, INPUT);
}

void loop()
{
  vlrSensor = analogRead(sensorTemp);
  temp = map(vlrSensor, 20, 358, -40, 125);//converte os dados enviados para °C
  
  if((millis() - temporizador) >= 2000){
  	temporizador = millis();
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println("°C");
    
    if(temp >= 20){
    	Serial.println("Tá quentinhoo!");
    }else if(temp <= 0){
    	Serial.println("Tá ficando friu ai!");
    }else{
    	Serial.println("Ta bão");
    }
  }
  
}