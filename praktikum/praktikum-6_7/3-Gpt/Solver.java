import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solver {
    private ArrayList<String> prompts;

    public Solver() {
        this.prompts = new ArrayList<String>();
    }

    public void addPiece(String prompt) {
        this.prompts.add(prompt);
    }

    public String scrapeAnswer() {
      // Kode berikut masih melakukan scrap ke GPT secara sekuensial.
      // Agar lebih cepat, ubahlah kode di bawah ini menjadi paralel
      // menggunakan wait dan notify, dengan membuat instance Scraper
      // Perhatikan juga bahwa piece answer di sini belum terurut.
      
      List<Scraper> scrapers = new ArrayList<>();
        
        // Create and start a Scraper thread for each prompt
        for (String prompt : prompts) {
            Scraper scraper = new Scraper(prompt);
            scrapers.add(scraper);
            scraper.start();
        }
        
        // Collect results from each Scraper
        StringBuilder answer = new StringBuilder();
        for (Scraper scraper : scrapers) {
            try {
                answer.append(scraper.getPieceAnswer());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Convert to a list of characters, sort it, and then form the final sorted string
        List<Character> sortedAnswer = new ArrayList<>();
        for (int i = 0; i < answer.length(); i++) {
            sortedAnswer.add(answer.charAt(i));
        }
        Collections.sort(sortedAnswer);

        StringBuilder sortedAnswerString = new StringBuilder();
        for (char c : sortedAnswer) {
            sortedAnswerString.append(c);
        }

        return sortedAnswerString.toString();
    }
}