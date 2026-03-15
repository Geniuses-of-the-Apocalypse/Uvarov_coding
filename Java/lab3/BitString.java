package ru.guu_java.lab3;

class BitString implements Array {

    private byte[] bits;
    private int length;

    // Конструктор из строки
    public BitString(String str) {
        if (str.length() > 100) {
            throw new IllegalArgumentException("Максимум 100 бит");
        }

        length = str.length();
        bits = new byte[length];

        for (int i = 0; i < length; i++) {
            if (str.charAt(i) == '0' || str.charAt(i) == '1') {
                bits[i] = (byte)(str.charAt(i) - '0');
            } else {
                throw new IllegalArgumentException("Строка должна содержать только 0 и 1");
            }
        }
    }

    // Метод сложения
    @Override
    public Array add(Array other) {

        if (!(other instanceof BitString)) {
            throw new IllegalArgumentException("Можно складывать только BitString");
        }

        BitString b = (BitString) other;
        int minLength = Math.min(this.length, b.length);
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < minLength; i++) {
            int sum = this.bits[i] ^ b.bits[i];
            result.append(sum);
        }
        return new BitString(result.toString());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++)
            sb.append(bits[i]);

        return sb.toString();
    }
}