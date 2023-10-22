package discussionExamples;

import java.io.*;

public class NoncompliantManner {

  public static void main(String[] args) {
    // Sensitive data
    String username = "john_doe";
    String password = "sensitive_password"; // Sensitive data

    // Logging the sensitive data to a log file
    try {
      // plain text file is unencrypted and can be read by anyone
      FileWriter fw = new FileWriter("log.txt", true);
      BufferedWriter bw = new BufferedWriter(fw);
      // Logging the sensitive data to a log file
      bw.write("Username: " + username + ", Password: " + password);
      bw.newLine();
      bw.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    // Sending sensitive data over an unsecured connection
    sendDataToServer(username, password);
  }

  public static void sendDataToServer(String username, String password) {
    // Code to send data to a remote server over HTTP without encryption
    // This is insecure and exposes sensitive data to potential attackers
  }
}
