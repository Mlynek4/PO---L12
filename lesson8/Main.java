
public class Main
{
    public static void main(String[] args) {
        Forecast forecast = new Forecast.Fake();
        Weather today = new Weather(4.0f, forecast);
        Weather x = today.currentTemp();
        System.out.println(x.toString());
        System.out.println(today.currentTemp());
        System.out.println(forecast.currentTemp(4.0f));
        assert "4.0".equals(x.toString());
    }
}
