float adc_value = 0;


#define led_pin 3
#define adc_pin A0
#define adc_ref_voltage 5

float read_adc_value(void);
void led_function(int brightness);

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
    led_function(real_voltage);
    
}

float read_adc_value(void){
    float value = 0;
    float voltage = 0;
    value = analogRead(adc_pin);
    voltage = (value / 1023) * adc_ref_voltage;
    return voltage;
}

void led_function(int brightness){
    analogWrite(led_pin,brightness);
}