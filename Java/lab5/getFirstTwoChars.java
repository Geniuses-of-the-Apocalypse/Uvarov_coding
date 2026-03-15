package ru.guu_java.lab5;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class getFirstTwoChars {
    /**
     * Возвращает первые два символа каждого слова в строке
     * @param text входной текст
     * @return строка из первых двух символов каждого слова
     */
    public static String getFTC(String text) {
        if (text == null || text.isEmpty()) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        /*
          \b - граница слова
          \p{L} - любая буква (включая русские)
          + - одно или более вхождений
         */
        Pattern pattern = Pattern.compile("\\b\\p{L}{2}", Pattern.UNICODE_CHARACTER_CLASS);
        Matcher matcher = pattern.matcher(text);

        while (matcher.find()) { result.append(matcher.group()); }
        return result.toString();
    }

}
