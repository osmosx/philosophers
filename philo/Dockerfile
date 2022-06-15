FROM gcc:latest AS builder
RUN apt-get update && apt-get install -y \
    make \
    gcc
COPY . /app
WORKDIR /app
RUN make
FROM ubuntu:latest
COPY --from=builder /app/philo .
ARG arg1 arg2 arg3 arg4
ENTRYPOINT ["./philo"]