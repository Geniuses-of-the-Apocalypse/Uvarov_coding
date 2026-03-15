package ru.guu_java.lab3;

class Fraction implements Array {

    private int sign;          // знак: 1 или -1
    private double value;      // значение
    private int precision;     // количество знаков после запятой

    // Конструктор
    public Fraction(double value, int precision) {
        if (value < 0) {
            this.sign = -1;
            this.value = -value;
        } else {
            this.sign = 1;
            this.value = value;
        }
        this.precision = precision;
    }

    // Конструктор копирования
    public Fraction(Fraction other) {
        this.sign = other.sign;
        this.value = other.value;
        this.precision = other.precision;
    }

    // Конструктор по умолчанию
    public Fraction() {
        this.sign = 1;
        this.value = 1;
        this.precision = 2;
    }

    // Метод сложения
    @Override
    public Array add(Array other) {
        if (!(other instanceof Fraction)) {
            throw new IllegalArgumentException("Можно складывать только Fraction");
        }

        Fraction f = (Fraction) other;
        double result = this.sign * this.value + f.sign * f.value;

        int maxPrecision = Math.max(this.precision, f.precision);
        return new Fraction(result, maxPrecision);
    }

    // Округление
    private double round(double val) {
        double scale = Math.pow(10, precision);
        return Math.round(val * scale) / scale;
    }

    @Override
    public String toString() {
        double result = round(sign * value);
        return String.format("%." + precision + "f", result);
    }
}