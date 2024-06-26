
#define led_pin 13
#define adc_pin A0
#define adc_ref_voltage 5

float read_adc_value(void);


void setup (){
    pinMode(led_pin, OUTPUT);
    pinMode(adc_pin,INPUT);
    Serial.begin(9600);
}
void loop (){
    float real_voltage = 0;
    real_voltage = read_adc_value();
    Serial.println("voltage = ");
    Serial.print(real_voltage);
    delay(100);
    if (real_voltage <= 3)          //voltage higher than 3 is called HIGH
    {     
        digitalWrite(led_pin,LOW);
    }
    else 
    {
        digitalWrite(led_pin,HIGH);
    }
    
}

float read_adc_value(void){
    float value = 0;
    float voltage = 0;
    value = analogRead(adc_pin);
    voltage = (value / 1023) * adc_ref_voltage;
    return voltage;
}
