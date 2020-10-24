//Juliusz Brzeziak

public class Decoder extends DecoderAbstraction {
  int times = 0;
  String bufer = "";
  String pod = "";
  boolean pd = false;

  public String getBuffer() {
    if (this.bufer == null) {
      return "";
    }

    else {
      return this.bufer;
    }
  }

  public void reset() {
    this.times = 0;
    this.bufer = "";
  }

  public void decode(String input) {
    StringBuilder helper = new StringBuilder(input);
    StringBuilder helperpod = new StringBuilder("");

    for (int i = 0; i < helper.length(); i++) {

      if (helper.charAt(i) == '0') {

        //00
        if (helper.charAt(i + 1) == '0') {
          reset();
          return;
        }
        //01 false
        else if (helper.charAt(i + 1) == '1' && this.pd == false) {
          this.pd = true;
          i = i + 1;
        }
        //01 true
        else if (helper.charAt(i + 1) == '1' && this.pd == true) {
          this.pd = false;
          for (int i3 = this.times; i3 > 0; i3--) {
            this.bufer = this.bufer + this.pod;
          }
          this.times = 0;
          this.pod = "";
          i = i + 1;
        }
        //0x
        else {
          this.times = helper.charAt(i + 1) - '0';
          i = i + 1;
        }

      }
      //01
      else if (this.pd == true) {
        this.pod = this.pod + helper.charAt(i);
      }
      //0x i następny nie jest 0
      else {
        if (this.times != 0 && this.pd == false) {
          for (int i3 = this.times; i3 > 0; i3--) {
            this.bufer = this.bufer + helper.charAt(i);
          }
          this.times = 0;
          return;
        }
        this.bufer = this.bufer + helper.charAt(i);

      }

    }

  }
