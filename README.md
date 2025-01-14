
# Minishell 👾

We developed a command interpreter inspired by Bash (POSIX norm)
which has as main role to allow connection between user and kernel.  
This project allowed us to discover more about the management of processes, redirections, pipes and signals.


## 👨‍💻 Project 
Basically, we create a prompt with readline.  

### Lexer part  
The input is first processed by a lexer whose purpose is to read the input character by character and split it into token according to what it represents (command, argument , operator, symbol ...)

### Parser part  
Then, the parser treat lexer results to group tokens together to form completes command in the right order.

### Execution part  
Once the parser provides a list of complete commands, the execution phase begins.  

Each command (except builtins alone) is executed in a child process created using fork. The main process (parent) is responsible for managing the shell, while each child process executes a specific command.  

Pipes are used to allow communication between commands. Each child process writes to and/or reads from a pipe to pass data to the next command in a pipeline.  
Pipes are used to redirect stdout of a process to stdin of the next one.

Each child process handles its own errors (e.g., returning an appropriate exit code on failure) closes the pipes and free ressources once it has finished using them. 

#### Expand 
Minishell performs variable expansion to replace environment variables (like $HOME, $PATH, etc.) in commands or arguments. This is done before execution to ensure the command receives the correct values.

#### Signals   
We had to implement signals handling (ctrl-C, ctrl-D, ctrl-\). It has been done using sigaction function allowing to define signal handler for each signal received.

#### Redirections  
Before processing to command execution we had to check if the command contains a redirection. If so, we redirect the command instead of the pipe.

#### Heredoc  
A here document is a method used in shell to define multi-line string. It has been handle by using a temporary file to store multi-line string. The difficulty here was handling signals and expand during heredoc management.


## 🔧 Build program  
Download, clone repo and use Makefile
```bash
git clone https://github.com/BdClement/Minishell.git
cd Minishell
make
```
Run executable file ./minishell


## 💼 Contributors  
- [Bastien Mirlicourtois](https://github.com/bmirlico)

