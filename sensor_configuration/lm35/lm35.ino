float adc_value = 0;


#define adc_pin A0
#define adc_ref_voltage 5

float lm35_data(void);

void setup (){
    pinMode(adc_pin,INPUT);
    Serial.begin(9600);
}
void loop (){
    float temp = 0;
    temp = lm35_data();
    Serial.println("voltage = ");
    Serial.print(temp);
    delay(100);
}

float lm35_data(void){
    float value = 0;
    float voltage = 0;
    voltage = analogRead(adc_pin);
    voltage = (voltage * 5)/1023;
    value = voltage * 1000 / 10;    //10mv/degree
    return value;
}