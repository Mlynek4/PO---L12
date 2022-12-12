
public class Weather {
    private final Forecast forecast;
    private float todayTemp;
    public Weather(float temperature, Forecast forecast){
        this.todayTemp=temperature;
        this.forecast=forecast;
    }
    
    public Weather currentTemp(){
        return new Weather(this.todayTemp, this.forecast);
    }
    
    @Override
    public String toString(){
        return Float.toString(todayTemp);
    }
}
