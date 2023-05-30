use PogLang::lex::lexer::Lexer;

fn main() {
    let mut pog = Lexer::new();
    pog.tokenizer("1ola");
    println!("{:?}", pog);
}
