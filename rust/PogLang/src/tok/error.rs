use std::fmt;

#[derive(Debug, PartialEq, Clone, Copy)]
pub enum TokenError {
    UnknownSymbol((usize, usize)),
}

impl fmt::Display for TokenError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Error: {:?}", self)
    }
}
