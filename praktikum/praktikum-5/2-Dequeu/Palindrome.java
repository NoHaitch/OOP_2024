public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq){
        Deque<T> temp = new Deque<T>(dq);
        Deque<T> reverse = new Deque<T>(dq);
        reverse.reverse();
        for(int i = 0; i < dq.size()/2; i++){
            try{
                if(reverse.popBack() != temp.popBack()){
                    return false;
                }
            } catch (Exception e){}
        }   
        
        return true;
    }
}
