public class Scraper extends Thread {
  private String prompt;
  private char pieceAnswer;
  private boolean isFinished = false;

  public Scraper(String prompt) {
      this.prompt = prompt;
  }

  @Override
  public void run() {
      Gpt gpt = new Gpt(prompt);
      pieceAnswer = gpt.getPieceAnswer();
      synchronized (this) {
          isFinished = true;
          notify();
      }
  }

  public synchronized char getPieceAnswer() throws InterruptedException {
      while (!isFinished) {
          wait();
      }
      return pieceAnswer;
  }
}
