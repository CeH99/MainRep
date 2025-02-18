public class NotReplace {
    public String notReplace(String str) {
        String result = "";

        for (int i = 0; i < str.length(); i++) {

            if (i + 1 < str.length() && str.substring(i, i + 2).equals("is")) {
                boolean isBeforeLetter = i > 0 && Character.isLetter(str.charAt(i - 1));
                boolean isAfterLetter = i + 2 < str.length() && Character.isLetter(str.charAt(i + 2));

                if (!isBeforeLetter && !isAfterLetter) {
                    result += "not is";
                    i += 1;
                    continue;
                }
            }
            result += str.charAt(i);
        }
        return result;
    }
}

