try
  {
    // Improper String Termination
    char unsafeBuffer[105];
    strncpy(unsafeBuffer, "This is a long string", sizeof(unsafeBuffer));
  }
  catch (const exception &e)
  {
    cerr << "Error: Improper String Termination\n";
    cerr << "Details: " << e.what() << : endl;
  }