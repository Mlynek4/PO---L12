
public interface Forecast {
    public float currentTemp(float todayTemp);
    final class Fake implements Forecast {
        @Override
        public float currentTemp(float todayTemp){
            return todayTemp;
        }
    }
}
