class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] Words = sentence.split(" ");
        for(int i = 0; i < Words.length; i++){
            if(Words[i].charAt(0) == searchWord.charAt(0) && searchWord.length() <= Words[i].length()){
                int flag = 0;
                for(int j = 1; j < searchWord.length(); j++){
                    if(Words[i].charAt(j) != searchWord.charAt(j)){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    return i+1;
                }
            }
        }
        return -1;
    }
}