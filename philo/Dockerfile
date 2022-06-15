FROM gcc:latest AS builder
RUN apt-get update && apt-get install -y \
    make \
    gcc
COPY . /app
WORKDIR /app
RUN make
FROM ubuntu:latest
COPY --from=builder /app/philo .
ENTRYPOINT ["./philo"]
