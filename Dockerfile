FROM alpine:latest

RUN apk update && \
    apk add --no-cache gcc g++ make tmux vim git python3

CMD ["sh"]